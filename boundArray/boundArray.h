#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

class BoundArray : public SafeArray {	// grandchild class
private:
	int low_;
	//int up_;

public:
	explicit BoundArray(int size = Array::ARRAY_SIZE);
	BoundArray(const int *pNum, int size);
	BoundArray(const BoundArray& rhs);
	BoundArray(int lower, int upper);
	~BoundArray();
	
	BoundArray& operator=(const BoundArray& rhs);
	
	bool operator==(const BoundArray& rhs) const;
	
	int lower() const;
	int upper() const;
	
	virtual int& operator[](int index);
	virtual const int& operator[](int index) const;
};

#endif
