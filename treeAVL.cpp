#include <iostream>
using namespace std;
class Node
{
    public:
    int data,height;
    Node*left,*right;
    Node(int val):data(val){left=right=NULL;height=1;}

};
Node*rightrotation(Node*root)
{
    Node *child = root->left;
    Node *childright = child->right;
    child->right=root;
    root->left=childright;
    //update height
    root->height = 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(child->left),getheight(child->right));
    return child;
}
Node*leftrotation(Node*root)
{
    Node*child=root->right;
    Node*childleft= child->left;
    child->left=root;
    root->right=childleft;
    //update height
    root->height = 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(child->left),getheight(child->right));
}
int getbalance(Node*root)
{
    return getheight(root->left)-getheight(root->right);
}
int getheight(Node*root)
{
    if(!root)return 0;
    return root->height;
}
Node*insert(Node*root,int key)
{
    if(!root)return new Node(key);

    if(key<root->data)root->left=insert(root->left,key);//left side
    else if(key>root->data)root->right=insert(root->right,key);//right side
    else return root;//duplicate elements not allowed

    root->height=1+max(getheight(root->left),getheight(root->right));

    int balance = getbalance(root);

    //left left
    if(balance>1 && key<root->left->data)
    {
        return rightrotation(root);
    }
    //right right
    else if(balance<-1 && key>root->right->data)
    {
        return leftrotation(root);
    }
    //left right
    else if(balance>1 && key>root->right->data)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    //right left
    else if(balance<-1 && key<root->left->data)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    //no unbalancing
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