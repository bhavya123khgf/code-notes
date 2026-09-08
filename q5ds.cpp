#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node*next;
    Node(int val):data(val){};

};
class List
{
    public:
    Node*head;
    Node*tail;
    
    List(){
        head=tail=NULL;
    }
    int counter()
    {
        int count=0;
        Node*temp= head;
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void printll()
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    void pushback(int val)
    {
        Node* newnode=new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
};
void intersection(List &l1,List &l2)
{
    int c1=l1.counter();
    int c2=l2.counter();
    if(c1!=c2){cout<<"the two lists are not of same length"<<endl;}
    else{
        Node*temp1=l1.head;
        Node*temp2=l2.head;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data==temp2->data){cout<<"intersection point"<< temp1->data<<endl;return;}
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
}
int main()
{
    List l1;
    List l2;
    l1.pushback(1);
    l1.pushback(2);
    l1.pushback(3);
    l1.pushback(4);
    l1.pushback(5);
    l1.printll();
    l2.pushback(6);
    l2.pushback(7);
    l2.pushback(3);
    l2.pushback(4);
    l2.pushback(5);
    l2.printll();
    intersection(l1,l2);
}