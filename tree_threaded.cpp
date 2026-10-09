#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*right,*left;
    bool rthread,lthread;
    Node(int val):data(val){right=left=NULL;rthread=lthread=true;}
};
Node*leftmost(Node*root)
{
    if(root==NULL)return;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
void inorder(Node*root)
{
    Node*curr=leftmost(root);
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        if(curr->rthread)curr=curr->right;
        else curr=leftmost(curr->right);
    }
}
Node* insert(Node *root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
    {
        if(root->lthread==false)
        {
            root->left=insert(root->left,val);
        }
        else
        {
            Node* newnode= new Node(val);
            newnode->left=root->left;
            newnode->right=root;
            root->left=newnode;
            root->lthread=false;
        }
    }
    else if(val > root->data)
    {
        if(root->rthread=false)
        {
            root->right=insert(root->right,val);
        }
        else
        {
            Node* newnode= new Node(val);
            newnode->left=root;
            newnode->right=root->right;
            root->right=newnode;
            root->rthread=false;
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}