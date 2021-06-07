#include<iostream>
using namespace std;

class Node
{
    public:
        Node();
        Node(int);
    private:
        int data;
        Node* first;
        Node* next;
    friend class Queue;
};

class Queue
{
    public:
        Queue();
        void enqueue(Node*);
        void dequeue();
        void peek();
        void display();
    private:
        Node* front;
        Node* rear;
};

Node::Node()
{
}
Node::Node(int d)
{
    data = d;
    first = next = NULL;
}

Queue::Queue()
{
    front = rear = NULL;
}
void Queue::enqueue(Node *n)
{
    if(front==NULL && rear==NULL)
        front = rear = n;
    else
    {
        rear->next = n;
        n->first = rear;
        rear = n;
    }
}
void Queue::dequeue()
{
    if(front==NULL && rear==NULL)
        cout<<"dequeue failure. queue empty\n";
    else if(front == rear)
        front = rear = NULL;
    else
    {
        front = front->next;
        front->first = NULL;
    }

}
void Queue::peek()
{
    if(front != NULL)
        cout<<"Peak value = "<<front->data<<"\n";
    else
        cout<<"Peek failure. Queue empty";
}
void Queue::display()
{
    Node* temp = front;
    cout<<"Queue elements : ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}



int main()
{
    Queue q;
    Node *n;

    n = new Node(10);
    q.enqueue(n);

    n = new Node(20);
    q.enqueue(n);

    n = new Node(30);
    q.enqueue(n);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    q.peek();
    return 0;
}