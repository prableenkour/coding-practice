#include<bits/stdc++.h>
using namespace std;
// Two sum

int main ()
{
    int arr[5]={3,4,5,6,8};
    int target=10;
    int l=0;
    int r=4;
    while(l<=r)
    {
        if((arr[l]+arr[r])==target)
        {
            cout<<l<<","<<r;
            exit(0);
        }
        else if((arr[l]+arr[r])>target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
// Brute Force
    // for(int i=0;i<sizeof(arr);i++)
    // {   
    //     for(int j=i+1;j<sizeof(arr);j++)
    //     if((arr[i]+arr[j])==target)
    //     {
    //         cout<<i+1;
    //         cout<<endl;
    //         cout<<j+1;
    //         exit(0);
    //     }
    // }
}