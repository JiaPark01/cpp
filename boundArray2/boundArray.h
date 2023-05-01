#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

template <typename T>
class BoundArray : public SafeArray<T> {	// grandchild class
private:
	int low_;

public:
	explicit BoundArray(int size = Array<T>::ARRAY_SIZE);
	BoundArray(const T *pNum, int size);
	//BoundArray(const BoundArray& rhs);
	BoundArray(int lower, int upper);
	//~BoundArray();
	
	//BoundArray& operator=(const BoundArray& rhs);
	
	bool operator==(const BoundArray<T>& rhs) const;
	
	int lower() const;
	int upper() const;
	
	virtual T& operator[](int index);
	virtual const T& operator[](int index) const;
};

	///////////////
	// from .cpp //
	///////////////

#include <cassert>

template <typename T>
BoundArray<T>::BoundArray(int size)
: SafeArray<T>(size), low_(0)
{

}
template <typename T>
BoundArray<T>::BoundArray(const T *pNum, int size)
: SafeArray<T>(pNum, size), low_(0)
{

}

template <typename T>
BoundArray<T>::BoundArray(int lower, int upper)
: SafeArray<T>(upper - lower), low_(lower)
{
	
}

template <typename T>
bool BoundArray<T>::operator==(const BoundArray<T>& rhs) const
{
	return this->SafeArray<T>::operator==( static_cast<SafeArray<T> >(rhs)) && low_ == rhs.low_;
}

template <typename T>
int BoundArray<T>::lower() const
{
	return low_;
}

template <typename T>
int BoundArray<T>::upper() const
{
	return low_ + this->SafeArray<T>::size();
}

template <typename T>
T& BoundArray<T>::operator[](int index)
{
	//assert(index >= this->lower() && index < this->upper());
	return this->SafeArray<T>::operator[](index - low_);
}

template <typename T>
const T& BoundArray<T>::operator[](int index) const
{
	//assert(index >= this->lower() && index < this->upper());
	return this->SafeArray<T>::operator[](index - low_);
}

#endif
