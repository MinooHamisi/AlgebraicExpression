#pragma once
#include<stddef.h>
template<class T>
class stack
{private:
	T *s;
	int top;
	int max;
public:
	stack() : top(-1) { s = new T[10]; max = 10; };
	stack(int max);
	~stack();
	void push(T c);
	T pop();
	bool empty();
	bool full();
	bool check(T element);
	bool closeCheck(T element);
	
	T returnTop();
	int elementNumber();


	
};

