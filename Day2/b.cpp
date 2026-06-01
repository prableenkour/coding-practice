#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n/2+1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j||i+j==n-1)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
         cout<<endl;
    }
   
}