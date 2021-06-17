#include <iostream>
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
        void inorder(Node*);
        void printOuterNodes(Node*, Node*);
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


void BSTtree::printOuterNodes(Node* temp, Node* root)
{
    if(temp)
    {
        printOuterNodes(temp->left, root);
        cout<<temp->data<<" ";
        if(temp == root)
        {
            temp = temp->right;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->right;
            }
        }
    }
}

int main()
{
    BSTtree bs;
    Node* root = NULL;

    root = bs.insert(root, 6);
    root = bs.insert(root, 5);
    root = bs.insert(root, 4);
    root = bs.insert(root, 3);
    root = bs.insert(root, 2);
    root = bs.insert(root, 1);
    root = bs.insert(root, 7);
    root = bs.insert(root, 8);

    cout<<"\nInorder : ";
    bs.inorder(root);

    cout<<"\nOuter nodes : ";
    bs.printOuterNodes(root, root);

    return 0;
}