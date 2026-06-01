#include<bits/stdc++.h>
using namespace std;
//max sum
//subarray means sliding window or two pointers
// if no constant then sliding window otherwise two pointer

int main()
{
    vector<int> arr={3,2,4,5,7};
    int k=2;
    int maxi=0;
    int sum=0;
    int left=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    maxi=max(sum,maxi);
    for(int i=k;i<arr.size();i++)
    {
        sum=arr[left++];
        sum+=arr[i];
        maxi=max(sum,maxi);

    }
    cout<<maxi;
    return 0;
}