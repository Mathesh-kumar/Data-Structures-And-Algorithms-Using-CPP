#include<iostream>
using namespace std;

class Queue
{
    int *a;
    int size;
    int front, rear;

    public:
        Queue(int);
        bool enqueue(int);
        bool dequeue();
        int peek();
        bool full();
        bool empty();
};

Queue::Queue(int s)
{
    size = s;
    a = new int(size);
    front = rear = -1;
}
bool Queue::enqueue(int element)
{
    if(full())
        return false;
    
    if(empty())
        front = rear = 0;
    else
        rear = (rear+1)%size;

    a[rear] = element;
    return true;
}
bool Queue::dequeue()
{
    if(empty())
        return false;
    if(front==rear)
        front = rear = -1;
    else
        front = (front+1)%size;
    return true;
}
int Queue::peek()
{
    if(!empty())
        return a[front];
    return -1;
}
bool Queue::full()
{
    if((rear+1)%size == front)
        return true;
    return false;
}
bool Queue::empty()
{
    if(front==-1 && rear==-1)
        return true;
    return false;
}


int main()
{
    int size;
    cout<<"Enter size of queue : ";
    cin>>size;

    Queue s(size);
    int choice;
    bool result;
    do{
        cout<<"Press 1.enqueue 2.dequeue 3.peek 4.full 5.empty 6.Exit\nYour's:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int num;
                cout<<"Enter num to enqueue:";
                cin>>num;
                result = s.enqueue(num);
                if(result)
                    cout<<"enqueue success\n";
                else
                    cout<<"enqueue failure. queue full\n";
                break;
            }
            case 2:
            {
                result = s.dequeue();
                if(result)
                    cout<<"dequeue success\n";
                else
                    cout<<"dequeue failure. queue empty\n";
                break;
            }
            case 3:
            {
                int peek = s.peek();
                if(peek==-1)
                    cout<<"Peek failure. queue empty\n";
                else
                    cout<<"Peek value = "<<peek<<"\n";
                break;
            }
            case 4:
            {
                if(s.full())
                    cout<<"queue full\n";
                else
                    cout<<"queue not full\n";
                break;
            }
            case 5:
            {
                if(s.empty())
                    cout<<"queue empty\n";
                else
                    cout<<"queue not empty\n";
                break;
            }
            case 6:
            {
                cout<<"Exited";
                exit(-1);
                break;
            }
            default:
            {
                cout<<"Invalid option\n";
                break;
            }
        }
    }while(choice!=6);

    return 0;
}