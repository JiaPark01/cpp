#ifndef STACK_H
#define STACK_H

// **structure defined in header files**

class Stack{
private:
	int *pArr;
	int size;
	int tos;

public:
	Stack(int size);			// constructor - void initStack(int size);
	~Stack();					// destructor - void cleanupStack();

	void push(int data);
	int pop();
};

#endif
