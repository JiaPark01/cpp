#include <iostream>
#include "list.h"

int main()
{
	List list1;
	//List list2 = list1;	X
	
	//list2 = list1;		X
	
	list1.insertFirst(4);		// [4]
	list1.insertFirst(2);		// [2, 4]
	list1.insertFirst(1);		// [1, 2, 4]
	
	list1.insert(2, 3);		// [1, 2, 3, 4] (ins 2 after 3)
	
	std::cout << list1 << std::endl;
	
	list1.remove(2);
	
	std::cout << list1 << std::endl;				// 1, 2, 4
	
	return 0;
}
