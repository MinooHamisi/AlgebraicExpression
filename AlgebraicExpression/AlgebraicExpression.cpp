// AlgebraicExpression.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"stack.h"
#include"stack.cpp"
#include <iostream>
using namespace std;
bool checkBalancedExp(char* c);
//--------------------------------------------------
int main()
{
	stack<char> s;
	cout << "please enter your algebric expression: \n";
	char c[20];
	cin >> c;
	checkBalancedExp(c);
	return 0;
}
//---------------------------------------------------
bool checkBalancedExp(char* c)
{
	stack<char> s;
	bool b = true;
	for (int i = 0; c[i] != NULL && b == true;i++)
	{
		if (c[i] == '(' || c[i] == '{' || c[i] == '[')
			s.push(c[i]);
		else
		{
			if (c[i] == ')' || c[i] == '}' || c[i] == ']')
			{
				if (s.check(c[i]))
					s.pop();
				else
					b = false;
			}
			else
			{
				if (c[i] == '-' || c[i] == '+' || c[i] == '*' || c[i] == '/' || c[i] == '%')
					if (!((c[i + 1] >= 48 && c[i + 1] <= 57) || (c[i + 1] >= 65 && c[i + 1] <= 90) || (c[i + 1] >= 97 && c[i + 1] <= 122)))
						b = false;
						//Character A – Z : ASCII Value 65 – 90
					    //Character a – z : ASCII Value 97 – 122
					    //Character 0 – 9 : ASCII Value 48 – 57
			}
		}
	}
	if (s.empty() && b == true)
	{
		cout << "the algebric expression is balanced!\n";
		return true;
	}
	else
	{
		cout << "the algebric expression is NOT balanced!\n";
		return false;
	}
}


