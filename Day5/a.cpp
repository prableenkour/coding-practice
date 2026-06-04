#include <bits/stdc++.h>
using namespace std;

class queues{
    public:
vector<int> q;
void push(int x) {
q.push_back(x);
}
void pop() {
q.erase(q.begin());
}
void front() {
cout<<q[0]<<endl;
}
void back() {
cout<<q[q.size()-1]<<endl;
}
void display() {
for(int i=0;i<q.size();i++){
    cout<<q[i]<<" ";
}
cout<<endl;
}
};

int main()
{
    queues q;
    q.push(1);
    q.pop();
    q.push(2);
    q.push(3);  
    q.push(4);
    q.push(5);
    q.front();
    q.back();
    q.display();
}