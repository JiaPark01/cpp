#include <cassert>
#include "stack.h"

const int Stack::STACK_SIZE = 100;

Stack::Stack(int size)		// reset local var (only global var is resetted)
: arr_(size), tos_(0)		// array의 생성자 호출해 초기화
{

}

/*
Stack::~Stack()
{
	delete [] pArr_;
}
*/

void Stack::push(int data)
{
	assert(!isFull());
	arr_[tos_] = data;
	++tos_;
}

int Stack::pop()
{
	assert(!isEmpty());
	--tos_;
	return arr_[tos_];
}

bool Stack::isFull() const
{
	return tos_ == arr_.size();
}

bool Stack::isEmpty() const
{
	return tos_ == 0;
}
