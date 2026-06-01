#include <iostream>
using namespace std;

    void printfull(int n){
        for(int i=1;i<=n;i++)
    {
        cout<<"*";
    }
    }
    void printhalf(int n){
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==n)
            {
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        
    }
    int main()
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            if(i==1||i==n)
            {
                printfull(n);
                cout<<endl;
            }
            else{
                printhalf(n);
                cout<<endl;
            }
        }
       
        
       
        
//     }


// {
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(i==n||j==m||i==0||j==0)
//             {
//                 cout<<"* ";
//             }
//         }
//     }
// }