#include<bits/stdc++.h>
using namespace std;

template<typename T>
// or
// template<class T>
// template<typename T,typename K>
// T sum(T a, K b)

//auto sum(auto a,auto b)
// {
//     return a+b
// }
// it will follow type promotionality rule which one has higher precedence it will follow that.



T sum(T a, T b)
{
    return a+b;
}
int main()
{
    cout<<sum(10,10);
}