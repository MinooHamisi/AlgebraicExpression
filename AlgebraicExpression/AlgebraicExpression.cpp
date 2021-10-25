// AlgebraicExpression.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"stack.h"
#include"stack.cpp"
#include <iostream>
using namespace std;
bool checkBalancedExp(char* c);
int calculate(string s);

string infixToPostfix(string s);
int prec(char c);
//--------------------------------------------------
int main()
{ 
	cout << "please enter your algebric expression: \n";
	char c[20];
	cin >> c;
	string st,postST;
	st += c;
	if (checkBalancedExp(c))
	{
		postST+=infixToPostfix(st);
		cout << "= " << calculate(postST) << endl;
	}
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
int calculate(string s)
{
	stack<int> st;
	int a,b;
	int result=0;
	for (int i = 0; i< s.length();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			st.push(s[i]-48);
		else
		{
			switch (s[i])
			{
			case '+':
				a = st.pop();
				b = st.pop();
				result = b + a;
				st.push(result);
				cout << result << "\n";
				break;
			case '-':
				a = st.pop();
				b = st.pop();
				result = b - a;
				st.push(result);
				cout << result << "\n";
				break;
			case '*':
				a = st.pop();
				b = st.pop();
				result = b * a;
				st.push(result);
				cout << result << "\n";
				break;
			case '/':
				a = st.pop();
				b = st.pop();
				result = b / a;
				st.push(result);
				cout << result << "\n";
				break;
			case '%':
				a = st.pop();
				b = st.pop();
				result = b % a;
				st.push(result);
				cout << result << "\n";
				break;
			case '^':
				a = st.pop();
				b = st.pop();
				result = b ^ a;
				st.push(result);
				cout << result << "\n";
				break;
			default:
				break;
			}
		}
	}
	return result;
}
//-----------------------------------------
string infixToPostfix(string s) 
{
		stack<char> st; 
		string result;

		for (int i = 0; i < s.length(); i++) 
		{
			char c = s[i];

			// If the scanned character is
			// an operand, add it to output string.
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
				result += c;

			// If the scanned character is an
			// ‘(‘, push it to the stack.
			else if (c == '('|| c == '['||c == '{')
				st.push(c);
			else if (c == ')'|| c == ']'|| c == '}')
			{
				while (!st.closeCheck(c))//top() != '('
				{
					result += st.returnTop();
					st.pop();
				}
				st.pop();
			}
			else //If an operator is scanned
			{
				cout << st.empty() << " && " << prec(s[i]) << " <= " << prec(st.returnTop()) << "\n";
				while (!st.empty() && prec(s[i]) <= prec(st.returnTop())) 
				{
					result += st.returnTop();
					st.pop();
					cout << "in the loop"<<st.empty() << " && " << prec(s[i]) << " <= " << prec(st.returnTop()) << "\n";
				}
				st.push(c);
			}
		}
		// Pop all the remaining elements from the stack
		while (!st.empty()) 
		{
			result += st.returnTop();
			st.pop();
		}

		cout << result << endl;
		return result;
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

