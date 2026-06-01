#include<bits/stdc++.h>
using namespace std;
class Rectangle
{public:
    int l,b;
    Rectangle( int l,int b)
{   this->l=l;
    this->b=b;
}
Rectangle& operator+(Rectangle& rhs)
{
this->l=this->l+rhs.l;
this->b=this->b+rhs.b;
return *this;
}
};
int main()
{
Rectangle r1(10,10);
Rectangle r2(10,10);
Rectangle r3=r1+r2;
cout<<r3.l<<r3.b;
return 0;
}