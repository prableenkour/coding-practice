#include<bits/stdc++.h>
using namespace std;
  bool repeated(string s)
    {
        string doubled=s+s;
        string trimmed=doubled.substr(1,doubled.size()-2);
        if(trimmed.find(s)!=string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

int main()
{
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    if(repeated(s))
    {
        cout<<"The string is repeated\n";
    }
    else
    {
        cout<<"The string is not repeated\n";
    }
  
}