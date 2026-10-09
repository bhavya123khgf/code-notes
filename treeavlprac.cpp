#include <iostream>
using namespace std;

class Node{
    public:
    int data,height;
    Node*left,*right;
    Node(int val):data(val){left=right=NULL;height=1;}
};
Node* rightrotation(Node*root)
{
    Node*child=root->left;
    Node*rightchild=child->right;
    child->right=root;
    root->left=rightchild;
    
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}

Node* leftrotation(Node*root)
{
    Node*child=root->right;
    Node*leftchild=child->left;
    child->left=root;
    root->right=leftchild;

    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}

int getheight(Node*root)
{
    return 1+max(getheight(root->left),getheight(root->right));
}
int getbalance(Node*root)
{
    return getheight(root->left)-getheight(root->right);
}
Node* insert(Node*root,int key)
{
    if(!root)return new Node(key);
    
    if(key<root->data)root->left = insert(root->left,key);
    else if(key>root->data)root->right = insert(root->right,key);
    else return root;

    root->height=1+max(getheight(root->left),getheight(root->right));
    int balance=getbalance(root);

    if(balance>1 && key<root->left->data)//left left
    {
        return rightrotation(root);
    }
    else if(balance>1 && key>root->left->data)//left right
    {
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
    else if(balance<-1 && key>root->right->data)//right right
    {
        return leftrotation(root);
    }
    else if(balance<-1 && key<root->right->data)//right left
    {
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }
    else
    {
        return root;
    }
}
int main()
{
    Node*root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,50);
    root=insert(root,70);
    root=insert(root, 5);
    root=insert(root,100);
    root=insert(root,95);
}