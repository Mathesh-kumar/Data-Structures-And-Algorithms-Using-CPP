#include<iostream>
using namespace std;

class Stack
{
    int *a;
    int top;
    int size;

    public:
        Stack(int);
        bool push(int);
        bool pop();
        int peek();
        bool full();
        bool empty();
};

Stack::Stack(int s)
{
    top = -1;
    size = s;
    a = new int(size);
}
bool Stack::push(int element)
{
    if(full())
        return false;
    a[++top] = element;
    return true;
}
bool Stack::pop()
{
    if(empty())
        return false;
    top--;
    return true;
}
int Stack::peek()
{
    if(empty())
        return -1;
    return a[top];
}
bool Stack::full()
{
    if(top == size-1)
        return true;
    return false;
}
bool Stack::empty()
{
    if(top == -1)
        return true;
    return false;
}


int main()
{
    int size;
    cout<<"Enter size of stack : ";
    cin>>size;

    Stack s(size);
    int choice;
    bool result;
    do{
        cout<<"Press 1.Push 2.Pop 3.Peek 4.full 5.empty 6.Exit\nYour's:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int num;
                cout<<"Enter num to push:";
                cin>>num;
                result = s.push(num);
                if(result)
                    cout<<"Push success\n";
                else
                    cout<<"Push failure. Stack full\n";
                break;
            }
            case 2:
            {
                result = s.pop();
                if(result)
                    cout<<"Pop success\n";
                else
                    cout<<"Pop failure. Stack empty\n";
                break;
            }
            case 3:
            {
                int peek = s.peek();
                if(peek==-1)
                    cout<<"Peek failure. Stack empty\n";
                else
                    cout<<"Peek value = "<<peek<<"\n";
                break;
            }
            case 4:
            {
                if(s.full())
                    cout<<"Stack full\n";
                else
                    cout<<"Stack not full\n";
                break;
            }
            case 5:
            {
                if(s.empty())
                    cout<<"Stack empty\n";
                else
                    cout<<"Stack not empty\n";
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