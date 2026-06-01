#include<bits/stdc++.h>
using namespace std;

class Animal{
    public:
    virtual void sound()
    {
        cout<<"General animal sound"<<endl;
    }
};
class dog:public Animal{
    public:
    void sound()
    {
        cout<<"bow bow"<<endl;
    }
};

int main()
{
    dog d;
    d.sound();
    d.Animal::sound();
    
    Animal* a=new dog;
    a->sound();
    return 7;
}
