/*
 * ============================================================
 *  TICKET RESERVATION SYSTEM
 *  - Max tickets     : 5
 *  - Confirmed seats : 2  (indices 0-1)
 *  - RAC seats       : 1  (index 2)  -- 2 passengers share 1 berth
 *  - Waiting list    : 2  (indices 3-4)
 *  - Classes         : Sleeper / AC / General
 *  - Data structures : array for seat/class info, queues for
 *                      RAC and Waiting-list, list for confirmed
 * ============================================================
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

// ─── Constants ───────────────────────────────────────────────
const int MAX_CONFIRMED  = 2;
const int MAX_RAC        = 1;   // 1 berth shared by ≤2 pax
const int MAX_WAITING    = 2;
const int MAX_TICKETS    = MAX_CONFIRMED + MAX_RAC + MAX_WAITING; // 5

// ─── Enumerations ────────────────────────────────────────────
enum class TicketStatus { CONFIRMED, RAC, WAITING };
enum class SeatClass    { SLEEPER, AC, GENERAL };

string classToStr(SeatClass c) {
    if (c == SeatClass::SLEEPER) return "Sleeper";
    if (c == SeatClass::AC)      return "AC";
    return "General";
}
string statusToStr(TicketStatus s) {
    if (s == TicketStatus::CONFIRMED) return "CONFIRMED";
    if (s == TicketStatus::RAC)       return "RAC";
    return "WAITING";
}

// ─── Data Structures ────────────────────────────no─────────────
struct User {
    string username;
    string password;
};

struct Ticket {
    int         ticketId;
    string      username;
    string      passengerName;
    int         age;
    SeatClass   seatClass;
    TicketStatus status;
    int         seatNumber;   // -1 if waiting
};


SeatClass classArray[MAX_TICKETS];

map<string, User>   userDB;          // username → User
map<int, Ticket>    ticketDB;        // ticketId → Ticket
int                 nextTicketId = 1001;


vector<int> confirmedSeats;          // list of ticket IDs in confirmed (max 2)
int         racSlots = 0;            // 0,1,or 2 passengers on RAC berth
queue<int>  racQueue;                // ticket IDs in RAC (≤2)
queue<int>  waitingQueue;            // ticket IDs waiting

string currentUser = "";             // logged-in user ("" = none)


void printLine(char c = '-', int n = 55) { cout << string(n, c) << "\n"; }

void printHeader(const string& title) {
    printLine('=');
    cout << "  " << title << "\n";
    printLine('=');
}

void printTicket(const Ticket& t) {
    printLine('-');
    cout << "  Ticket ID   : " << t.ticketId        << "\n"
         << "  Passenger   : " << t.passengerName   << " (age " << t.age << ")\n"
         << "  Class       : " << classToStr(t.seatClass) << "\n"
         << "  Status      : " << statusToStr(t.status)   << "\n";
    if (t.status == TicketStatus::CONFIRMED)
        cout << "  Seat No.    : " << t.seatNumber << "\n";
    else if (t.status == TicketStatus::RAC)
        cout << "  Berth No.   : RAC-1 (shared)\n";
    else
        cout << "  Position    : Waiting List\n";
}


void registerUser() {
    printHeader("REGISTER");
    string uname, pwd, pwd2;
    cout << "  Username : "; cin >> uname;
    if (userDB.count(uname)) { cout << "  [!] Username already exists.\n"; return; }
    cout << "  Password : "; cin >> pwd;
    cout << "  Confirm  : "; cin >> pwd2;
    if (pwd != pwd2) { cout << "  [!] Passwords do not match.\n"; return; }
    userDB[uname] = {uname, pwd};
    cout << "  [✓] Registered successfully!\n";
}

bool loginUser() {
    printHeader("LOGIN");
    string uname, pwd;
    cout << "  Username : "; cin >> uname;
    cout << "  Password : "; cin >> pwd;
    if (!userDB.count(uname) || userDB[uname].password != pwd) {
        cout << "  [!] Invalid credentials.\n";
        return false;
    }
    currentUser = uname;
    cout << "  [✓] Welcome, " << uname << "!\n";
    return true;
}

void logoutUser() {
    cout << "  [✓] Logged out. Goodbye, " << currentUser << "!\n";
    currentUser = "";
}


void bookTicket() {
    if (currentUser.empty()) { cout << "  [!] Please login first.\n"; return; }

    printHeader("BOOK TICKET");

    string name; int age; int classChoice;
    cout << "  Passenger Name : "; cin.ignore(); getline(cin, name);
    cout << "  Age            : "; cin >> age;
    cout << "  Select Class   : 1) Sleeper  2) AC  3) General\n  Choice : ";
    cin >> classChoice;
    if (classChoice < 1 || classChoice > 3) { cout << "  [!] Invalid class.\n"; return; }

    SeatClass sc = (classChoice == 1) ? SeatClass::SLEEPER
                 : (classChoice == 2) ? SeatClass::AC
                 :                      SeatClass::GENERAL;

    Ticket t;
    t.ticketId      = nextTicketId++;
    t.username      = currentUser;
    t.passengerName = name;
    t.age           = age;
    t.seatClass     = sc;
    t.seatNumber    = -1;

    
    if ((int)confirmedSeats.size() < MAX_CONFIRMED) {
        // Confirmed seats: seat numbers 1 and 2
        t.seatNumber = (int)confirmedSeats.size() + 1;
        t.status     = TicketStatus::CONFIRMED;
        confirmedSeats.push_back(t.ticketId);
        // store class in classArray slot index = seatNumber-1
        classArray[t.seatNumber - 1] = sc;

    } else if (racSlots < 2) {
        // RAC berth (1 berth, max 2 passengers)
        t.status = TicketStatus::RAC;
        racQueue.push(t.ticketId);
        classArray[2] = sc;   // slot index 2 = RAC
        racSlots++;

    } else if ((int)waitingQueue.size() < MAX_WAITING) {
        int wPos = (int)waitingQueue.size();   // 0 or 1
        t.status = TicketStatus::WAITING;
        waitingQueue.push(t.ticketId);
        classArray[3 + wPos] = sc;             // slots 3 and 4

    } else {
        cout << "  [!] All tickets (confirmed + RAC + waiting) are full. Cannot book.\n";
        return;
    }

    ticketDB[t.ticketId] = t;
    cout << "\n  [✓] Ticket booked!\n";
    printTicket(t);
}


void promoteQueues() {
    // If confirmed seat freed → move first RAC passenger to confirmed
    if ((int)confirmedSeats.size() < MAX_CONFIRMED && !racQueue.empty()) {
        int tid = racQueue.front(); racQueue.pop(); racSlots--;
        Ticket& t = ticketDB[tid];
        int seat = (int)confirmedSeats.size() + 1;
        t.status     = TicketStatus::CONFIRMED;
        t.seatNumber = seat;
        confirmedSeats.push_back(tid);
        classArray[seat - 1] = t.seatClass;
        cout << "  [→] Ticket " << tid << " (" << t.passengerName
             << ") promoted from RAC to CONFIRMED (Seat " << seat << ").\n";
    }

  
    if (racSlots < 2 && !waitingQueue.empty()) {
        int tid = waitingQueue.front(); waitingQueue.pop();
        Ticket& t = ticketDB[tid];
        t.status = TicketStatus::RAC;
        racQueue.push(tid);
        classArray[2] = t.seatClass;
        racSlots++;
        cout << "  [→] Ticket " << tid << " (" << t.passengerName
             << ") promoted from WAITING to RAC.\n";
    }
}

void cancelTicket() {
    if (currentUser.empty()) { cout << "  [!] Please login first.\n"; return; }

    printHeader("CANCEL TICKET");
    int tid;
    cout << "  Enter Ticket ID to cancel : "; cin >> tid;

    if (!ticketDB.count(tid)) { cout << "  [!] Ticket not found.\n"; return; }
    Ticket& t = ticketDB[tid];
    if (t.username != currentUser) { cout << "  [!] This ticket doesn't belong to you.\n"; return; }

    cout << "\n  Cancelling ticket for " << t.passengerName << "...\n";

    if (t.status == TicketStatus::CONFIRMED) {
        // Remove from confirmedSeats
        confirmedSeats.erase(
            remove(confirmedSeats.begin(), confirmedSeats.end(), tid),
            confirmedSeats.end());
        // Re-number remaining confirmed seats
        for (int i = 0; i < (int)confirmedSeats.size(); ++i) {
            ticketDB[confirmedSeats[i]].seatNumber = i + 1;
            classArray[i] = ticketDB[confirmedSeats[i]].seatClass;
        }
        promoteQueues();

    } else if (t.status == TicketStatus::RAC) {
        // Remove from racQueue (rebuild)
        queue<int> newRac;
        while (!racQueue.empty()) {
            int id = racQueue.front(); racQueue.pop();
            if (id != tid) newRac.push(id);
            else racSlots--;
        }
        racQueue = newRac;
        promoteQueues();

    } else { // WAITING
        queue<int> newWait;
        while (!waitingQueue.empty()) {
            int id = waitingQueue.front(); waitingQueue.pop();
            if (id != tid) newWait.push(id);
        }
        waitingQueue = newWait;
    }

    ticketDB.erase(tid);
    cout << "  [✓] Ticket " << tid << " cancelled successfully.\n";
}


void viewMyTickets() {
    if (currentUser.empty()) { cout << "  [!] Please login first.\n"; return; }
    printHeader("MY TICKETS — " + currentUser);
    bool found = false;
    for (auto& [id, t] : ticketDB) {
        if (t.username == currentUser) { printTicket(t); found = true; }
    }
    if (!found) cout << "  No tickets found.\n";
    printLine('-');
}

void viewAllTickets() {
    printHeader("ALL TICKETS (Admin View)");

    cout << "\n  ── CONFIRMED SEATS ──\n";
    for (int id : confirmedSeats) printTicket(ticketDB[id]);

    cout << "\n  ── RAC ──\n";
    queue<int> tmp = racQueue;
    if (tmp.empty()) cout << "  (empty)\n";
    while (!tmp.empty()) { printTicket(ticketDB[tmp.front()]); tmp.pop(); }

    cout << "\n  ── WAITING LIST ──\n";
    queue<int> tmp2 = waitingQueue;
    if (tmp2.empty()) cout << "  (empty)\n";
    while (!tmp2.empty()) { printTicket(ticketDB[tmp2.front()]); tmp2.pop(); }

    printLine('-');
}


void showAvailability() {
    printHeader("SEAT AVAILABILITY");
    cout << "  Confirmed  : " << confirmedSeats.size()  << " / " << MAX_CONFIRMED << "\n";
    cout << "  RAC        : " << racSlots               << " / 2 passengers (1 berth)\n";
    cout << "  Waiting    : " << waitingQueue.size()    << " / " << MAX_WAITING   << "\n";

    cout << "\n  ── classArray (slot → class) ──\n";
    string slotNames[] = {"Confirmed-1", "Confirmed-2", "RAC-1", "Waiting-1", "Waiting-2"};
    for (int i = 0; i < MAX_TICKETS; ++i) {
        bool occupied = false;
        if (i < (int)confirmedSeats.size()) occupied = true;
        if (i == 2 && racSlots > 0)         occupied = true;
        queue<int> wq = waitingQueue;
        if (i == 3 && !wq.empty())          occupied = true;
        if (i == 4 && wq.size() >= 2)       occupied = true;

        cout << "  [" << setw(11) << slotNames[i] << "] "
             << (occupied ? classToStr(classArray[i]) : "(free)") << "\n";
    }
}

// ─── Main Menu ───────────────────────────────────────────────
void mainMenu() {
    while (true) {
        printLine('=');
        cout << "  TICKET RESERVATION SYSTEM\n";
        if (!currentUser.empty())
            cout << "  Logged in as : " << currentUser << "\n";
        printLine('-');
        cout << "  1. Register\n"
             << "  2. Login\n"
             << "  3. Book Ticket\n"
             << "  4. Cancel Ticket\n"
             << "  5. My Tickets\n"
             << "  6. All Tickets (Admin)\n"
             << "  7. Seat Availability\n"
             << "  8. Logout\n"
             << "  9. Exit\n";
        printLine('-');
        cout << "  Choice : "; int ch; cin >> ch;

        switch (ch) {
            case 1: registerUser();   break;
            case 2: loginUser();      break;
            case 3: bookTicket();     break;
            case 4: cancelTicket();   break;
            case 5: viewMyTickets();  break;
            case 6: viewAllTickets(); break;
            case 7: showAvailability(); break;
            case 8: logoutUser();     break;
            case 9: cout << "  Goodbye!\n"; return;
            default: cout << "  [!] Invalid choice.\n";
        }
        cout << "\n";
    }
}

int main() {
    // Seed a default admin account for testing
    userDB["admin"] = {"admin", "admin123"};

    mainMenu();
    return 0;
}