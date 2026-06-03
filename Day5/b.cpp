#include<bits/stdc++.h>
using namespace std;

class stacks{
    public:
vector<int> s;
void push(int x) {
s.push_back(x);
}
void pop() {
s.pop_back();
}
void top() {
cout<<s[s.size()-1]<<endl;
}
void display() {
for(int i=s.size()-1;i>=0;i--){
    cout<<s[i]<<" ";
}
}
};
int main()
{
    stacks s;
    s.push(1);
    s.pop();
    s.push(2);
    s.push(3);  
    s.push(4);
    s.push(5);
    s.top();
    s.display();
}