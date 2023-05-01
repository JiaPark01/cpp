#ifndef STACK_H
#define STACK_H
#include "array.h"

template <typename T>
class Stack{
private:
	static const int STACK_SIZE;

	Array<T> arr_;					// 'has-a 관계' - stack has an array
	int tos_;
	
	Stack(const Stack<T>& rhs);	// to prevent from copying, private
	Stack<T>& operator=(const Stack<T>& rhs);
	
public:
	explicit Stack(int size = Stack<T>::STACK_SIZE);	// constructor - void initStack(int size);
	//~Stack();					// destructor included in Array

	void push(const T& data);
	T pop();		// pop 하면서 내려오는데 이미 지나온 공간을 reference 쓰는 건 이상함
	
	bool isFull() const;
	bool isEmpty() const;
};


#include <cassert>

template <typename T>
const int Stack<T>::STACK_SIZE = 100;

template <typename T>
Stack<T>::Stack(int size)		// reset local var (only global var is resetted)
: arr_(size), tos_(0)		// array의 생성자 호출해 초기화
{

}

/*
template <typename T>
Stack<T>::~Stack()
{
	delete [] pArr_;
}
*/

template <typename T>
void Stack<T>::push(const T& data)
{
	assert(!isFull());
	arr_[tos_] = data;
	++tos_;
}

template <typename T>
T Stack<T>::pop()
{
	assert(!isEmpty());
	--tos_;
	return arr_[tos_];
}

template <typename T>
bool Stack<T>::isFull() const
{
	return tos_ == arr_.size();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return tos_ == 0;
}

#endif
