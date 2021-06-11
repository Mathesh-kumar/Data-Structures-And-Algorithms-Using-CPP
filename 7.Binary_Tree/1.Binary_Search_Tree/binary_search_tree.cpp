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
        int empty();
        int insert(Node*, Node*);
        int remove();
        int search();
        void inorder(Node*);
        int postorder(Node*);
        int preorder(Node*);
        Node* getroot();
    private:
        Node* root;
};

Node::Node(int d)
{
    data = d;
    left = right = NULL;
}

BSTtree::BSTtree()
{
    root = NULL;
}

int BSTtree::empty()
{
    if(root == NULL)
        return 1;
    return 0;
}

int BSTtree::insert(Node* temp, Node* n)
{
    if(empty())
        root = n;
    else
    {
        cout<<"inside insert : "<<temp->data<<endl;
        if(temp->data > n->data)
        {
            if(temp->left == NULL)
                temp->left = n;
            else
                insert(temp->left, n);
        }
        else if(temp->data < n->data)
        {
            if(temp->right == NULL)
                temp->right = n;
            else
                insert(temp->right, n);
        }
        else
            return 0;
    }
    return 1;
}

int BSTtree::remove()
{
    
}

int BSTtree::search()
{
    
}

void BSTtree::inorder(Node* temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

int BSTtree::preorder(Node* temp)
{
    
}

int BSTtree::postorder(Node* temp)
{
    
}

Node* BSTtree::getroot()
{
    return root;
}

int main()
{
    BSTtree bs;
    Node* n;
    int res;

    n = new Node(10);
    res = bs.insert(bs.getroot(), n);

    n = new Node(5);
    res = bs.insert(bs.getroot(), n);

    n = new Node(20);
    res = bs.insert(bs.getroot(), n);

    bs.inorder(bs.getroot());

    return 0;
}