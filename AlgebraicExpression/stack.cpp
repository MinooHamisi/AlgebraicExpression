#include "stack.h"
#include<stddef.h>
using namespace std;

template<class T>
stack<T>::stack(int max)
{
	s = new T[max];
	top = -1;
}

template<class T>
stack<T>::~stack()
{
	delete s;
}

template<class T>
void stack<T>::push(T c)
{
	top++;
	s[top] = c;
}

template<class T>
T stack<T>::pop()
{
	T temp= s[top];
	--top;
	return temp;
}

template<class T>
bool stack<T>::empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template<class T>
bool stack<T>::full()
{
	if (top == (max - 1))
		return true;
	else
		return false;
}

template<class T>
bool stack<T>::check(T element)
{
	if (s[top] == element)
		return true;
	else
		return false;
}

template<class T>
bool stack<T>::closeCheck(T element)
{
	switch (element)
	{case ')':
		return this->check('(');
		break;
	case '}':
		return this->check('{');
		break;
	case ']':
		return this->check('[');
		break;
	default:
		return false;
		break;
	}
}

template<class T>
int stack<T>::elementNumber()
{
	return top+1;
}
