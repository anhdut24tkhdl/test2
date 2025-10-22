#pragma once

#include"Move.h"
class Stack 
{
	
	Move* arr;
	int top;
	int capacity;

public :
	Stack(const int& );
	~Stack();
	
	void Push(const Move& move);
	Move Pop();
	Move Top();
	int IsEmpty();
	int IsFull();
	void clear() { top = -1; }
		
};

