#include<iostream>
using namespace std;

class Node
{
    public:
        Node(int);
    private:
        int data;
        Node* next;
    friend class List;
};

class List
{
    public:
        List();
        void insert(Node*);
        void remove(int);
        void largestNumber();
        void smallestNumber();
        bool empty();
        void display();
    private:
        Node* start;
};

Node::Node(int d)
{
    data = d;
    next = NULL;
}

List::List()
{
    start = NULL;
}

void List::insert(Node* n)
{
    if(start==NULL)
        start = n;
    else
    {
        Node* temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}

void List::remove(int data)
{
    Node* temp = start;
    Node* prev;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            if(temp==start)
            {
                if(temp->next == NULL)
                    start = NULL;
                else
                    start = temp->next;
                break;
            }
            else
            {
                prev->next = temp->next;
                break;
            }
        }
        prev = temp;
        temp = temp->next;
    }
}

void List::largestNumber()
{
    if(start==NULL)
    {
        cout<<"List empty\n";
    }
    else
    {
        Node* temp = start;
        int maxNumber = temp->data;
        temp = temp->next;
        while(temp!=NULL)
        {
            if(temp->data > maxNumber)
                maxNumber = temp->data;
            temp = temp->next;
        }
        cout<<"Largest number in the list : "<<maxNumber<<endl;
    }
}

void List::smallestNumber()
{
    if(start==NULL)
    {
        cout<<"List empty\n";
    }
    else
    {
        Node* temp = start;
        int minNumber = temp->data;
        temp = temp->next;
        while(temp!=NULL)
        {
            if(temp->data < minNumber)
                minNumber = temp->data;
            temp = temp->next;
        }
        cout<<"Largest number in the list : "<<minNumber<<endl;
    }
}

bool List::empty()
{
    if(start==NULL)
        return true;
    return false;   
}

void List::display()
{
    Node* temp = start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    List l;
    Node* n;

    n = new Node(10);
    l.insert(n);

    n = new Node(20);
    l.insert(n);

    n = new Node(30);
    l.insert(n);

    l.display();

    l.largestNumber();
    l.smallestNumber();

    l.remove(20);
    l.remove(40);
    l.remove(10);

    l.display();

    n = new Node(50);
    l.insert(n);

    l.display();

    l.largestNumber();
    l.smallestNumber();

    return 0;
}