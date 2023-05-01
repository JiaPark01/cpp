#include <cassert>
#include "queue.h"

const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}
/*
Queue::Queue(const Queue& rhs)
: arr_(rhs.arr), front_(rhs.front_), rear_(rhs.rear_)
{

}

Queue& Queue::operator=(const Queue& rhs)
{
	arr_ = rhs.arr_;
	front_ = rhs.front_;
	rear_ = rhs.rear_;
	
	return *this;
}

Queue::~Queue()
{

}
*/

void Queue::push(int data)
{
	assert(!isFull());
	
	arr_[rear_] = data;
	//++rear_;
	rear_ = (rear_ + 1) % arr_.size();
}

int Queue::pop()
{
	assert(!isEmpty());
	
	int i = front_;
	//++front_;
	front_ = (front_ + 1) % arr_.size();
	return arr_[i];
}

bool Queue::isFull() const
{
	return (rear_ + 1) % arr_.size() == front_;
}

bool Queue::isEmpty() const
{
	return front_ == rear_;
}

/*
bool Queue::isAtEnd() const
{
	return rear_ == front_ && rear_ == size_;
}
*/
