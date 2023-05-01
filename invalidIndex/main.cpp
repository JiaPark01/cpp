#include <iostream>
#include "safeArray.h"

int main()
{
	int nums1[] = {1, 2, 3, 4, 5};
	SafeArray<int> arr1(nums1, 5);
	
	for (int i = 0; i < arr1.size(); ++i) {
		std::cout << "arr1 [" << i << "] : " << arr1[i] << std::endl;
	}
	
	std::cout << std::endl;
	
	double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	SafeArray<double> arr2(nums2, 5);
	
	for (int i = 0; i < arr2.size(); ++i) {
		std::cout << "arr2 [" << i << "] : " << arr2[i] << std::endl;
	}
	
	std::cout << std::endl;
		
	try {
		char chars1[] = {'a', 'b', 'c', 'd', 'e'};
		SafeArray<char> arr3(chars1, 5);
		
		for (int i = 0; i < arr3.size(); ++i) {
			std::cout << "arr3 [" << i << "] : " << arr3[i] << std::endl;
		}
		
		std::cout << std::endl;
		
		arr2[5] = 6.6;
		
	//} catch (int e) {
	} catch (const InvalidIndex& e) {
		std::cerr << "array boundary error index : " << e.invalid() << std::endl;
	}
	
	return 0;
}
