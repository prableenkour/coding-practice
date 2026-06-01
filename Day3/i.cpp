#include<bits/stdc++.h>
using namespace std;

// remove duplicates
int main(){
vector<int> v={1,2,2,3,3,4,4,4,5,9,10};
int n=v.size();
int idx=1;
for(int i=1;i<n;i++)
{
    if(v[i]!=v[i-1]) v[idx++]=v[i];
}
cout<<"Total Unique elements:"<<idx<<endl;
for(int i : v )
{
     cout<<i<<" ";
}
}