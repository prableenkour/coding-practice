#include<bits/stdc++.h>
using namespace std;
//triplets forming a triangle
//two pointer

int main()
{
    vector<int> arr={2,2,3,4};
    sort(arr.begin(),arr.end());
    int cnt=0;
    int n=4;
    for(int i=0;i<arr.size();i++)
    {
        int temp=arr[i];
        int l=i+1;
        int r=n-1;
        while(l<r)
        {
            if(arr[l]+arr[r]>temp){
                cnt++;
                r--;
            }
            else 
            {
                l++;
            }
        }
       
    }
     cout<<cnt;
    
}

// 
// sort(nums.begin(),nums.end());
// int n=nums.size();
// int count=0;
// for(int hypo=n-1;hypo>=1;hypo--)
// 
// 
// 
// 
