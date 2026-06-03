#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    string rev;
    int len=s.length();
    for(int i=len-1;i>=0;i--)
    {
        rev+=s[i];
    }
    cout<<rev;
    return 0;
}