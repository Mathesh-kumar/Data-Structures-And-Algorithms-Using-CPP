#include<iostream>
using namespace std;

class Node
{
    public:
        Node(int);
    private:
        int data;
        Node* left;
        Node* right;
    friend class BSTtree;
};

class BSTtree
{
    public:
        BSTtree();
        Node* insert(Node*, int);
        int remove(Node*, int);
        int search(Node*, int);
        void inorder(Node*);
        void postorder(Node*);
        int countNodes(Node*);
};

Node::Node(int d)
{
    data = d;
    left = right = NULL;
}

BSTtree::BSTtree()
{
}

// function to insert a new node into the tree
Node* BSTtree::insert(Node* root, int n)
{
    if(root == NULL)
        return new Node(n);
    else
    {
        if(root->data > n)
            root->left = insert(root->left, n);
        else if(root->data < n)
            root->right = insert(root->right, n);
        else
            return root;
    }
    return root;
}

int BSTtree::remove(Node* root, int n)
{
}

// function to srach particular node in the tree
int BSTtree::search(Node* root, int n)
{
    Node* temp = root;
    while(temp != NULL)
    {
        if(temp->data == n)
            return 1;
        else if(temp->data > n)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return 0;
}

// function to print the nodes in inorder traversal
void BSTtree::inorder(Node* temp)
{
    if(temp)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

// function to print the nodes in postorder traversal
void BSTtree::postorder(Node* temp)
{
    if(temp)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

// function to count no of nodes in the binary tree
int BSTtree::countNodes(Node* root)
{
    if(root == NULL)
        return 0;
    else
        return countNodes(root->left)+countNodes(root->right)+1;
}

int main()
{
    BSTtree bs;
    Node* root = NULL;

    cout<<"\nNo of nodes in the tree : "<<bs.countNodes(root);

    root = bs.insert(root, 6);
    root = bs.insert(root, 2);
    root = bs.insert(root, 1);
    root = bs.insert(root, 11);
    root = bs.insert(root, 8);
    root = bs.insert(root, 9);
    root = bs.insert(root, 10);
    root = bs.insert(root, 15);

    cout<<"\nInorder : ";
    bs.inorder(root);

    cout<<"\nPostorder : ";
    bs.postorder(root);

    int out;
    out = bs.search(root, 15);
    cout<<((out)?"\nData found":"\nData not found");

    cout<<"\nNo of nodes in the tree : "<<bs.countNodes(root);
    return 0;
}