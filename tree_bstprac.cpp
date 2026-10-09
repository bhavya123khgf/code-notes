#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left,*right;
    Node(int val):data(val){left=right=NULL;}

};
void inorder(Node*root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node*insert(Node*root,int val)
{
    if(root==NULL)
    {Node *temp= new Node(val);return temp;}
    if(val<root->data)root->left=insert(root->left,val);
    else if(val>root->data)root->right=insert(root->right,val);
    else return;
}
bool search(Node*root,int key)
{
    if(root==NULL)return 0;
    if (root->data==key) return 1;
    else if(root->data<key)return search(root->left,key);
    else return search(root->right,key);
}
int main()
{
    int arr[]={3,7,4,1,6,8};
    Node*root;
    for(int i=0;i<6;i++)
    root=insert(root,arr[i]);
    inorder(root);
}