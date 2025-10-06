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
	
	void Push(Move move);
	Move Pop();
	Move Top();
	int IsEmpty();
	int IsFull();

		
};

