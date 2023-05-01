#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

class Queue {
private:
	static const int QUEUE_SIZE;
	
	Array arr_;
	//int *pArr_;
	//int size_;
	int front_;
	int rear_;
	
public:
	explicit Queue(int size = Queue::QUEUE_SIZE);
	//Queue(const Queue& rhs);
	//~Queue();
	
	//Queue& operator=(const Queue& rhs);
	
	void push(int data);
	int pop();
	
	bool isFull() const;
	bool isEmpty() const;
	//bool isAtEnd() const;
};

#endif
