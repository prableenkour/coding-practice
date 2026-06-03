#include<bits\stdc++.h>
using namespace std;

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

int main()
{
    string name;
    cout<<"Enter the name :\n";
    cin>>name;
    cout<<substring(1,3,name);

}