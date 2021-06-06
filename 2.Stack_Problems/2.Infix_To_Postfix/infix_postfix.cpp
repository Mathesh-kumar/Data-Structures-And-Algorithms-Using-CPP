#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int precedence(char opr)
{
    switch(opr)
    {
        case '(':
            return 1;
        case '-':
            return 2;
        case '+':
            return 2;
        case '*':
            return 3;
        case '/':
            return 3;
        case '^':
            return 4;
    }
}

void infixToPostfix(string exp)
{
    stack<char> s;

    int j;
    for(j=0; exp[j]; j++);
    cout<<j<<endl;

    for(int i=0; i<j; i++)
    {
        if(isalpha(exp[i]))
        {
            cout<<exp[i];
        }
        else
        {
            if((s.empty() || exp[i]=='(' || precedence(exp[i])>precedence(s.top())) && exp[i]!=')')
            {
                s.push(exp[i]);
            }
            else
            {
                if(exp[i]==')')
                {
                    while(s.top() != '(')
                    {
                        cout<<s.top();
                        s.pop();
                    }
                    s.pop();
                }
                else if(precedence(s.top())>=precedence(exp[i]))
                {
                    while(!s.empty() && precedence(s.top())>=precedence(exp[i]))
                    {
                        if(s.top()=='(')
                        {
                            break;
                        }
                        cout<<s.top();
                        s.pop();
                    }
                    s.push(exp[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}


int main()
{
    string expression;
    cout<<"Enter infix expression,\n";
    cin>>expression;

    cout<<"Enter postfix expression,\n";
    infixToPostfix(expression);
    return 0;
}