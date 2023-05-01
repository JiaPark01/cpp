#ifndef STACK_H
#define STACK_H
#include "array.h"

class Stack{
private:
	static const int STACK_SIZE;
	
	//int *pArr_;
	//int size_;
	Array arr_;					// 'has-a 관계' - stack has an array
	int tos_;
	
	Stack(const Stack& rhs);	// to prevent from copying, private
	Stack& operator=(const Stack& rhs);
	
public:
	explicit Stack(int size = Stack::STACK_SIZE);	// constructor - void initStack(int size);
	//~Stack();					// destructor included in Array

	void push(int data);
	int pop();
	
	bool isFull() const;
	bool isEmpty() const;
};

#endif
