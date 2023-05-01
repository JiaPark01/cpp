#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

class SafeArray : public Array {
private:
	//static const int SAFE_ARRAY_SIZE;		// protected로 바꿔줬으니 부모 클래스의 ARRAY_SIZE 가져오면 됨
	
public:
	explicit SafeArray(int size = Array::ARRAY_SIZE);
	SafeArray(const int *pNum, int size);
	
	//SafeArray(const SafeArray& rhs);	// copy
	//virtual ~SafeArray();						// destructer
	//SafeArray& operator=(const SafeArray & rhs);
	
	bool operator==(const SafeArray& rhs) const;
	
	virtual int& operator[](int index);
	virtual const int& operator[](int index) const;
	
};

#endif
