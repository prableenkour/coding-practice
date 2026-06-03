#include<bits/stdc++.h>
using namespace std;

string is_pali(string s)
{
    int len=s.length();
    string rev;
    for(int i=len-1;i>=0;i--)
    {
        rev+=s[i];
    }
    return rev;
}

int main()
{
    string s;
    cout<<"enter the string:\n";
    cin>>s;
    if(s==is_pali(s))
    {
        cout<<"The string is a palindrome\n";
    }
    else
    {
        cout<<"The string is not a palindrome\n";
    }
}
