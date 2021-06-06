#include<iostream>
using namespace std;

class Node
{
    public:
        Node();
        Node(int);
    private:
        int data;
        Node* next;
    friend class Stack;
};

class Stack
{
    public:
        Stack();
        void push(Node*);
        void pop();
        void peek();
        void display();
    private:
        Node* top;
};

Node::Node()
{
}
Node::Node(int d)
{
    data = d;
    next = NULL;
}

Stack::Stack()
{
    top = NULL;
}
void Stack::push(Node *n)
{
    if(top != NULL)
        n->next = top;
    top = n;
}
void Stack::pop()
{
    if(top != NULL)
        top = top->next;
}
void Stack::peek()
{
    if(top != NULL)
        cout<<"Peek value : "<<top->data<<"\n";
    else
        cout<<"Stack is empty";
}
void Stack::display()
{
    Node* temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}



int main()
{
    Stack s;
    Node *n;

    n = new Node(10);
    s.push(n);

    n = new Node(20);
    s.push(n);

    n = new Node(30);
    s.push(n);

    s.display();

    s.peek();

    s.pop();

    s.display();

    s.peek();
    return 0;
}