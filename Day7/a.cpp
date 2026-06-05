#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

void traverse(Node* head ){
    while(head && head!=nullptr) {
        cout<<head->data<<"-> ";
        head=head->next;
    }
}
void addNewNode(Node* head,int val)
{
    if(!head) return;
    while(head->next)
    {
        head=head->next;
    }
    head->next=new Node(val);
}
void addatbeg(Node* &head,int val){
  Node* newNode = new Node(val);
  newNode->next = head;
  head= newNode;
}
void addatmiddle(Node* head,int val,int pos)
{
    if(!head) addatbeg(head,val);
    pos-=2;int count=0;
    while(head && count<pos)
    {
        head=head->next;
        count++;
    }
    head->next=new Node(val);
}

int main(){

    Node* head = new Node(5);
    Node* n1 = new Node(10);
    head->next=n1;
    Node* n2 = new Node(15);
    n1->next=n2;
    Node* n3 = new Node(20);
    n2->next=n3;
    Node* n4 = new Node(25);
    n3->next=n4;
    n4->next=nullptr;
    traverse(head);

    return 0;
}
