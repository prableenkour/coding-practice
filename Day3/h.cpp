#include<bits/stdc++.h>
using namespace std;
//rotate the array

int main()
{
    vector<int> v={1,2,3,4};
    int k;
    cin>> k;
    k=k%v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    for(int i:v)
    {
            cout<<i<<" "; 
    }
    
    }


    // int first=arr[0];
    // int last=arr[3];
    // for(int i=0;i<3;i++)
    // {
    //     arr[i+1]=arr[i];
    // }
    // arr[0]=first;



    

