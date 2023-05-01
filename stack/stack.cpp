//#include <stdlib.h>		// exit, malloc
#include <cassert>
#include "stack.h"

Stack::Stack(int size)		// reset local var (only global var is resetted)
{
	//this->pArr = (int *)malloc(sizeof(int) * size);
	this->pArr = new int[size];
	assert(this->pArr);	// in case not assigned any space, stop
	this->size = size;
	this->tos = 0;
}

Stack::~Stack()
{
	//free(this->pArr);
	delete [] this->pArr;
}

void Stack::push(int data)
{
	assert(this->tos != this->size);
	this->pArr[this->tos] = data;
	++this->tos;
}

int Stack::pop()
{
	assert(this->tos);
	--this->tos;
	return this->pArr[this->tos];
}
