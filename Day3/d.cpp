#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool flag=true;
    int arr[5]={1,10,11};
    for(int i=0;i<sizeof(arr);i++)
    {
        if(arr[i]==12)
        {
            flag=false;
            break;
        }
    }
    if(flag==false)
    {
        cout<<"found!!";
    }
    else
    {
        cout<<"Not found!!";
    }

}