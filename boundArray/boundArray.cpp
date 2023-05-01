#include <cassert>
#include "boundArray.h"

BoundArray::BoundArray(int size)
: SafeArray(size), low_(0)
{

}

BoundArray::BoundArray(const int *pNum, int size)
: SafeArray(pNum, size), low_(0)
{

}

BoundArray::BoundArray(int lower, int upper)
: SafeArray(upper - lower), low_(lower)
{
	
}

BoundArray::BoundArray(const BoundArray& rhs)
: SafeArray( static_cast<SafeArray>(rhs)), low_(rhs.low_)
{

}

BoundArray::~BoundArray()
{

}

BoundArray& BoundArray::operator=(const BoundArray& rhs)
{
	this->SafeArray::operator=( static_cast<SafeArray>(rhs));
	low_ = rhs.low_;
	return *this;
}

bool BoundArray::operator==(const BoundArray& rhs) const
{
	return this->SafeArray::operator==( static_cast<SafeArray>(rhs)) && low_ == rhs.low_;
}

int BoundArray::lower() const
{
	return low_;
}

int BoundArray::upper() const
{
	return low_ + this->Array::size();
}

int& BoundArray::operator[](int index)
{
	assert(index >= this->lower() && index < this->upper());
	return this->Array::operator[](index);
}

const int& BoundArray::operator[](int index) const
{
	assert(index >= this->lower() && index < this->upper());
	return this->Array::operator[](index);
}
