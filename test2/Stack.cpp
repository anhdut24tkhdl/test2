#include "Stack.h"
Stack::Stack(const int& capacity)
{
	this->top = -1;
	this->capacity = capacity;
	this->arr = new Move[capacity];
}

Stack::~Stack()
{
	delete[] arr;
}
int Stack::IsEmpty()
{
	return top == -1;
}
int Stack::IsFull()
{
	return top == capacity - 1;
}
void Stack::Push(Move move )
{
	if (IsFull())
		return;
	arr[++top] = move;

}	
Move Stack::Pop()
{
	if (IsEmpty())
	{
		return Move();
	}
	return arr[top--];
}Move Stack::Top()
{
	if (IsEmpty())
	{
		return Move();
	}
	return arr[top];
}