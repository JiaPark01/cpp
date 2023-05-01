#include <iostream>

#include "boundArray.h"

int main()
{
	BoundArray arr1;				// BoundArray arr1(100);
	BoundArray arr2(20);
	int nums[] = {1, 2, 3, 4, 5};
	BoundArray arr3(nums, 5);
	BoundArray arr4(5, 8);			// index [1, 8] 1, 2, 3, 4, 5, 6, 7
	
	arr1 = arr2;
	
	if (arr1 == arr2) {
		std::cout << "arr1 and arr2 are equal" << std::endl;
	} else {
		std::cout << "arr1 and arr2 are not equal" << std::endl;
	}
	
	//std::cout << arr2.lower() << std:endl;
	
	/*
	for (int i = arr2.lower(); i < arr2.upper(); ++i) {
		arr2[i] = i;
		//std::cout<< i << std::endl;
	}
	
	for (int i = arr2.lower(); i < arr2.upper(); ++i) {
		std::cout << "arr2[" << i << "] : " << arr2[i] << std::endl;
	}
	*/
	for (int i = arr4.lower(); i < arr4.upper(); ++i) {
		arr4[i] = i;
		//std::cout<< i << std::endl;
	}
	
	std::cout << "arr4 size:" << arr4.size() << ", upper : " << arr4.upper() << std::endl;
	
	for (int i = arr4.lower(); i < arr4.upper(); ++i) {
		std::cout << "arr4[" << i << "] : " << arr4[i] << std::endl;
	}
	
	
	return 0;
}
