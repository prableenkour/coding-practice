#include<bits\stdc++.h>
using namespace std;

// STRING FUNCTIONS

string substring(int start,int end,string org)
{
    int l=start;
    int r=end;
    string orginal=org;
    string result;
    for(int i=l;i<=end;i++)
    {
        result+=orginal[i];
    }
    return result;
}
bool is_emptyy(int start,int end,string org)
{
    int l=start;
    int r=end;
    string orginal=org;
    for(int i=l;i<=end;i++)
    {
        if(orginal[i]!=' ')
        {
            return false;
        }
    }
    return true;
}
int finds(int start,int end,string org,char chr)
{
    int l=start;
    int r=end;
    string orginal=org;
    char k=chr;
    int i;
    for(int i=l;i<=end;i++)
    {
        if(orginal[i]==k)
        {
            return i;
            break;
        }
    }
    return i;

    
}

string appendd(string original,string newstring)
{
    string orgstr=original;
    string newstr=newstring;
    orgstr+=newstr;
    return orgstr;
}

int main()
{
    bool flag=true;
    string name;
    cout<<"Enter the name :\n";
    cin>>name;
    cout<<substring(1,3,name)<<endl;
    cout<<is_emptyy(1,2,name)<<endl;
    cout<<finds(1,5,name,'r')<<endl;
    cout<<appendd(name," kour");

}