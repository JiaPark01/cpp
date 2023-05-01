//#include <cstdio>
#include <iostream>
#include "queue.h"

int main()
{
	Queue q1;			// Queue q1(100);
	Queue q2(100);		// Queue q1 = 100; X
	
	//Queue q3 = q2;		// X
	q1 = q2;			// X
	
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	std::cout << "q1 1st pop() : " << q1.pop() << std::endl;
	std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;
	std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;
	
	for (int i = 1; i <= 3 ; ++i) {
		if (!q2.isFull()) {
			q2.push(i);
		}
	}
	Queue q3 = q2;		// X
	
	while (1) {
		if (q2.isEmpty()) {
			break;
		} else {
			std::cout << "q2 pop() : " << q2.pop() << std::endl;
		}
	}
	
	while (1) {
		if (q3.isEmpty()) {
			break;
		} else {
			std::cout << "q3 pop() : " << q3.pop() << std::endl;
		}
	}
	
	return 0;
}
