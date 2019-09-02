// made by Anilabha Baral
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};
Node *newNode(int value)
{
    Node *node=new Node;
    node->value=value;
    node->left=NULL;
    node->right=NULL;
    return node;

}
Node *insert(Node *root,int value)
{
    if (root==NULL)
    {
        return newNode(value);

    }
    if (value<root->value)
    {
        root->left=insert(root->left,value);
    }
    if (value>root->value)
    {
        root->right=insert(root->right,value);
    }

    return root;

}

void print_treepreorder(Node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        cout<<root->value<<endl;
        print_treepreorder(root->left);
        print_treepreorder(root->right);

    }
}
void print_treepostorder(Node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {

        print_treepostorder(root->left);
        print_treepostorder(root->right);
        cout<<root->value<<endl;

    }
}
void print_treeinorder(Node *root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {

        print_treeinorder(root->left);
                cout<<root->value<<endl;

        print_treeinorder(root->right);

    }
}

Node *findmin_value(Node *root){
if (root==NULL)
    return root;
while(root->left !=NULL){
    root=root->left;
}
return root;


}

Node *findmax(Node *root){
if (root==NULL)
    return root;
while(root->right !=NULL){
    root=root->right;

}
return root;

}
int size(Node *root){
if (root==NULL){
    return 0;

}
else {
    return (size(root->left)+1+size(root->right));
}

}

int main()
{
    Node *root=NULL;
    root=insert(root,10);
    insert(root,4);
    insert(root,6);

    insert(root,1);

    insert(root,3);
    insert(root,8);
    insert(root,5);
    insert(root,2);
    insert(root,9);
    cout<<"pre-order\n";
    print_treepreorder(root);
        cout<<"post-order\n";
        print_treepostorder(root);
            cout<<"in-order\n";
            print_treeinorder(root);


   cout<<"\n";
cout<<"Min value="<<findmin_value(root)->value;
  cout<<"\n";
cout<<"max value="<<findmax(root)->value;
cout<<"\n";
cout<<"size of tree = "<<size(root);


    return 0;
}
