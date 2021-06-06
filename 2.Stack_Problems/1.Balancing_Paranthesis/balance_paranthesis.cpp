#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;


#define nl endl
#define array(type, name, size) type *name = new type[size]
#define mod 1000000007
#define wl() int n; cin>>n; while(n--)
#define finc(start, end) for(int i=start; i<end; i++)
#define fdec(start, end) for(int i=start; i>=end; i--)


int main()
{
	stack<int> s;
	string input;

	cout<<"Enter input paranthesis,\n";
	cin >> input;

	int flag = 0;
	string bracesClose = "}])";

	finc(0, input.length())
	{
		char ip = input[i];
		if (s.empty())
		{
			if (bracesClose.find(ip) != string::npos) {
				flag = 1;
				break;
			}
			else
				s.push(ip);
		}
		else
		{
			char top = s.top();
			if ((ip == ')' && top == '(') || (ip == '}' && top == '{') || (ip == ']' && top == '['))
				s.pop();
			else
				s.push(ip);
		}
	}

	if (flag == 0 && s.empty())
		cout << "Balanced";
	else
		cout << "Not Balanced";

	return 0;
}