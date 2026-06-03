#include<bits\stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    int c=0;
    int len=s.length();
    for(int i=len;i>=0;i--)
    {
        if (s[i]!=' ')
        {
            c++;

        }
        else if(c>0)
        {
            break;
        }
    }
    cout<<c-1;

}

// /*
// int solve(string s)
// {
//     int count=0;
//     stringstream ss(s);
//     string word, res;
//     while(ss>>word){
//         res=word;
//     }
//     count=res.size();
//     return count;
// }
// */