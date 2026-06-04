#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int ,string> m;
    m[1]="one";
    m[2]="two";
    m[3]="three";
    m[4]="four";
    for(auto i:m){
        cout<<i.first<<" ->"<<i.second<<endl;
    }
    
}