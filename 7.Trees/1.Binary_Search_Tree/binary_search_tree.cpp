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
        int remove(int);
        int search(int);
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

int BSTtree::remove(int n)
{
    Node* child = root;
    Node* parent;
    
    while(child != NULL)
    {
        if(child->data == n)
        {
            if(child->left==NULL && child->right==NULL)
            {
                if(child == root)
                    root = NULL;
                else if(child == parent->left)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else if(child->left==NULL && child->right!=NULL)
            {
                if(child == root)
                    root = child->right;
                else  
                    parent->right = child->right;
            }
            else if(child->left!=NULL && child->right==NULL)
            {
                if(child == root)
                    root = child->left;
                else  
                    parent->left = child->left;
            }
            else
            {
                Node* schild = child->right;
                Node* sparent = schild;
                while(schild->left != NULL)
                {
                    sparent = schild;
                    schild = schild->left;
                }
                child->data = schild->data;
                if(sparent == schild)
                    child->right = schild->right;
                else
                    sparent->left = schild->right;
            }

            return 1;
        }

        parent = child;
        if(child->data > n) 
            child = child->left;
        else
            child = child->right;
    }

    return 0;
}

int BSTtree::search(int n)
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

    n = new Node(6);
    res = bs.insert(bs.getroot(), n);

    n = new Node(2);
    res = bs.insert(bs.getroot(), n);

    n = new Node(1);
    res = bs.insert(bs.getroot(), n);

    n = new Node(11);
    res = bs.insert(bs.getroot(), n);

    n = new Node(8);
    res = bs.insert(bs.getroot(), n);

    n = new Node(9);
    res = bs.insert(bs.getroot(), n);

    n = new Node(10);
    res = bs.insert(bs.getroot(), n);

    n = new Node(15);
    res = bs.insert(bs.getroot(), n);

    cout<<"\nInorder : ";
    bs.inorder(bs.getroot());

    cout<<"\nPreorder : ";
    bs.preorder(bs.getroot());

    cout<<"\nPostorder : ";
    bs.postorder(bs.getroot());

    int out = bs.search(28);
    if(out == 0)
        cout<<"\nData not found";
    else
        cout<<"\nData found";

    res = bs.remove(6);

    if(res == 1)
        cout<<"\nDeletion success.";
    else
        cout<<"\nNo element to delete. Deletion failure";

    cout<<"\nInorder : ";
    bs.inorder(bs.getroot());


    return 0;
}