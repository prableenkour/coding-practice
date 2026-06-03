#include<bits/stdc++.h>
using namespace std;

int lenOfsub(string s)
{
    int right=0,left=0;
    int cnt[128]={0};
    int maxi=0;
    for(right; right<s.size();right++)
    {
        cnt[s[right]]++;
        while(cnt[s[right]]>1)
        {
            cnt[s[left]]--;
            left++;
        }
        maxi=max(maxi,right-left+1);
    }
    return maxi;
}
int main()
{
    string s;
    cout<<"Enter the string:\n";
    cin>>s;
    cout<<lenOfsub(s);
}