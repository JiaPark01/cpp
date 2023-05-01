#include <cassert>
#include "queue.h"

const int Queue::QUEUE_SIZE = 100;

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0), rear_(0)
{
	assert(pArr_);
}

Queue::Queue(const Queue& rhs)
: pArr_(new int[rhs.size_]), size_(rhs.size_), front_(rhs.front_), rear_(rhs.rear_)
{
	// copy	
	for (int i = 0; i < rhs.size_; ++i) {
		pArr_[i] = rhs.pArr_[i];
	}
}

Queue& Queue::operator=(const Queue& rhs)
{
	// substitution
	if (this != &rhs) {
		// del
		delete [] pArr_;
		pArr_ = new int[rhs.size_];
		assert(pArr_);
		
		// copy
		size_ = rhs.size_;
		front_ = rhs.front_;
		rear_ = rhs.rear_;
		
		for (int i = 0; i < rhs.size_; ++i) {
			pArr_[i] = rhs.pArr_[i];
		}
	}
	
	return *this;
}

Queue::~Queue()
{
	delete [] pArr_;
}


void Queue::push(int data)
{
	assert(!isFull());
	
	pArr_[rear_] = data;
	//++rear_;
	rear_ = (rear_ + 1) % size_;
}

int Queue::pop()
{
	assert(!isEmpty());
	
	int i = front_;
	//++front_;
	front_ = (front_ + 1) % size_;
	return pArr_[i];
}

bool Queue::isFull() const
{
	return (rear_ + 1) % size_ == front_;
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
