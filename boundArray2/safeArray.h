#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

template <typename T>
class SafeArray : public Array<T> {
private:
	
public:
	explicit SafeArray(int size = Array<T>::ARRAY_SIZE);
	SafeArray(const T *pNum, int size);
	//SafeArray(const SafeArray<T>& rhs);	// copy
	//virtual ~SafeArray();						// destructer
	//SafeArray<T>& operator=(const SafeArray<T> & rhs);
	
	bool operator==(const SafeArray<T>& rhs) const;
	
	virtual T& operator[](int index);
	virtual const T& operator[](int index) const;	
};
	//////////////
	// from cpp //
	//////////////

template <typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size)
{
	
}

template <typename T>
SafeArray<T>::SafeArray(const T *pNum, int size)
: Array<T>(pNum, size)
{

}

/*
template<typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
: Array<T>( static_cast<Array<T> >(rhs))		// slicing
{

}

template<typename T>
SafeArray<T>::~SafeArray()
{

}

template<typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)
{
	this->Array<T>::operator=( static_cast<Array<T> >(rhs));
	
	return *this;
}
*/

template <typename T>
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
	return this->Array<T>::operator==( static_cast<Array<T> >(rhs));
	//return (Array<T>)*this == (Array<T>)rhs;
}

template <typename T>
T& SafeArray<T>::operator[](int index)
{
	assert(index >= 0 && index < this->Array<T>::size_);		// 이미 자식 클래스로 받아와서 size() 만 써도 됨
	return this->Array<T>::operator[](index);
}

template <typename T>
const T& SafeArray<T>::operator[](int index) const
{
	assert(index >= 0 && index < this->Array<T>::size_);
	return this->Array<T>::operator[](index);
}

#endif
