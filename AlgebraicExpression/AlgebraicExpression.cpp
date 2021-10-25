// AlgebraicExpression.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"stack.h"
#include"stack.cpp"
#include <iostream>
using namespace std;
bool checkBalancedExp(char* c);
int calculate(char* c);

void infixToPostfix(string s);
int prec(char c);
//--------------------------------------------------
int main()
{ 
	cout << "please enter your algebric expression: \n";
	char c[20];
	cin >> c;
	string st;
	st += c;
	if (checkBalancedExp(c))
		//cout << "= " << calculate(c)<<endl;
		infixToPostfix(st);
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
				if (s.closeCheck(c[i]))
					s.pop();
				else
					b = false;
			}
			else
			{
				if (c[i] == '-' || c[i] == '+' || c[i] == '*' || c[i] == '/' || c[i] == '%')
					//if (!((c[i + 1] >= 48 && c[i + 1] <= 57) || (c[i + 1] >= 65 && c[i + 1] <= 90) || (c[i + 1] >= 97 && c[i + 1] <= 122) || c[i+1] == '(' || c[i+1] == '{' || c[i+1] == '['))
					if(c[i+1] == ')' || c[i+1] == '}' || c[i+1] == ']')
						b = false; // it is not a number or an alphabet
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
//----------------------------------------
int calculate(char* c)
{
	stack<int> SN;//stack number
	stack<char> SO;//stack operation
	int result=0;
	for (int i = 0; c[i] != NULL;i++)
	{
		if (c[i] >= 48 && c[i] <= 57)// if it is a number
			SN.push(c[i] - 48); //char is changed to an integer number => -48
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/' || c[i] == '%' || c[i] == '^')
			SO.push(c[i]);
		//if
	}
	return result;
}
//-----------------------------------------

void infixToPostfix(string s) 
{
		stack<char> st; //For stack operations, we are using C++ built in stack
		string result;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];

			// If the scanned character is
			// an operand, add it to output string.
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
				result += c;

			// If the scanned character is an
			// ‘(‘, push it to the stack.
			else if (c == '(')
				st.push('(');
			else if (c == ')') 
			{
				while (!st.check('('))//top() != '(')
				{
					result += st.returnTop();
					st.pop();
				}
				st.pop();
			}

			//If an operator is scanned
			else {
				while (!st.empty() && prec(s[i]) <= prec(st.returnTop())) {
					result += st.returnTop();
					st.pop();
				}
				st.push(c);
			}
		}
		// Pop all the remaining elements from the stack
		while (!st.empty()) {
			result += st.returnTop();
			st.pop();
		}

		cout << result << endl;
}
//------------------------------------------------
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
//------------------------------------------

