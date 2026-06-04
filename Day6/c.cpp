#include<bits\stdc++.h>
using namespace std;

auto sync=ios::sync_with_stdio(false);
auto untie_cin=cin.tie(0);
auto untie_cout=cout.tie(0);

class person{
    string name;
    string age;
    long phone_no;
    string status;
};
class admin:public person{
    public:
    int n;

};
class admin2:public admin
{

};
int main()
{
    admin2 a;
    a.n = 2;
    cout<<a.n;

}