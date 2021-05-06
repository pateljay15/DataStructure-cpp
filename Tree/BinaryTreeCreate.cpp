#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * create()
{
    struct Node * newNode = new struct Node[sizeof(struct Node)];
    int val;
    cout<<"Enter the data for the node (Press -1 for no data)"<<endl;
    cin>>val;

    if(val == -1){
        return NULL;
    }
    else
    {
        newNode->data = val;
        cout<<"Enter the value of the left Node"<<endl;
        newNode->left = create();
        cout<<"Enter the value of the right Node"<<endl;
        newNode->right = create();
        return newNode;
    }
};

void preOrder(struct Node *root)
{
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    struct Node * root;
    root = NULL;
    root = create();
    cout<<"PreOrder Traversal"<<endl;
    preOrder(root);
    cout<<endl<<"InOrder Traversal"<<endl;
    inOrder(root);
    cout<<endl<<"PostOrder Traversal"<<endl;
    postOrder(root);
}
