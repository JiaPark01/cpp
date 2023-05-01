#ifndef STACK_H
#define STACK_H

class Stack{
private:
	static const int STACK_SIZE;
	
	int *pArr_;
	int size_;
	int tos_;
	
	Stack(const Stack& rhs);	// to prevent from copying, private
	Stack& operator=(const Stack& rhs);
	
public:
	explicit Stack(int size = Stack::STACK_SIZE);	// constructor - void initStack(int size);
	~Stack();					// destructor - void cleanupStack();

	void push(int data);
	int pop();
	
	bool isFull() const;
	bool isEmpty() const;
};

#endif
