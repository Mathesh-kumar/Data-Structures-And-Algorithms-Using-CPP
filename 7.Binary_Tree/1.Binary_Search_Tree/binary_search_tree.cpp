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
        void inorder(Node*);
        void postorder(Node*);
        void preorder(Node*);
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

void BSTtree::inorder(Node* temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void BSTtree::preorder(Node* temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BSTtree::postorder(Node* temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
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

    n = new Node(20);
    res = bs.insert(bs.getroot(), n);

    n = new Node(30);
    res = bs.insert(bs.getroot(), n);

    n = new Node(5);
    res = bs.insert(bs.getroot(), n);

    n = new Node(2);
    res = bs.insert(bs.getroot(), n);

    n = new Node(15);
    res = bs.insert(bs.getroot(), n);

    n = new Node(40);
    res = bs.insert(bs.getroot(), n);

    n = new Node(1);
    res = bs.insert(bs.getroot(), n);

    n = new Node(3);
    res = bs.insert(bs.getroot(), n);

    n = new Node(2);
    res = bs.insert(bs.getroot(), n);

    n = new Node(7);
    res = bs.insert(bs.getroot(), n);

    n = new Node(29);
    res = bs.insert(bs.getroot(), n);

    cout<<"\nInorder : ";
    bs.inorder(bs.getroot());

    cout<<"\nPreorder : ";
    bs.preorder(bs.getroot());

    cout<<"\nPostorder : ";
    bs.postorder(bs.getroot());

    return 0;
}