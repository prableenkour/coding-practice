#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void registers()
{
    string name,ui,pass;
    cout<<"Name:\n UI:\nPassword:\n";
    cin>>name>>ui>>pass;
}
void login()
{
    string ui,pass;
    cout<<"UI:\nPassword:\n";
    cin>>ui>>pass;
}
void admin()
{
     string ui,pass;
    cout<<"UI:\nPassword:\n";
    cin>>ui>>pass;
}
void logout()
{
    cout<<"Logout successfull!!";
}
void exit()
{

}
int main()
{
   bool flag=true;
while(flag)
{
     int n;
    cout<<"Enter the choice:\n 1.Register \n2.Login \n3.Admin Login \n4.Logout \n5.Exit\n";
    cin>>n;
    switch(n)
    {
        case 1:registers();
               break;
        case 2:login();
               break;
        case 3:admin();
               break;
        case 4:logout();
               break;
        case 5:exit();
        default:break;
    }
}
}