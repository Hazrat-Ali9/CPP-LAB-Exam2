#include<bits/stdc++.h>
using namespace std;

int Stack(char x)
{
	if(x == '*' || x == '/')
		return 3;
	if(x == '+' || x == '-')
		return 4;

	return INT_MAX;
}

bool isOperand(char x)
{
	return(x >= 'a' && x <= 'z');
}

string infixToPostfix(string infix)
{
	stack<char>s;
	string postfix;
	for(char x: infix)
	{
		if(x == '('){
			s.push(x);
		}
		else if(x == ')')
		{
			while(s.top() != '(')
			{
				postfix.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else if(isOperand(x)){
			postfix.push_back(x);
		}
		else
		{
			while(!s.empty() && Stack(x) >= Stack(s.top()))
			{
				postfix.push_back(s.top());
				s.pop();
			}
			s.push(x);
		}
	}

	while(!s.empty())
	{
		postfix.push_back(s.top());
		s.pop();
	}

	return postfix;
}

int main()
{
	string infix;
	cin>>infix;
	string postfix = infixToPostfix(infix);
	cout<<postfix<<endl;
	return 0;
}
