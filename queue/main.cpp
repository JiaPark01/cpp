#include <iostream>
#include "queue.h"


int main()
{
	Queue q1(100), q2(10);
	
	q1.push(100);			// send address to change q1 which is structure
	q1.push(200);
	q1.push(300);
	
	std::cout << "q1 1st pop() : " << q1.pop() << std::endl;
	std::cout << "q1 2nd pop() : " << q1.pop() << std::endl;
	std::cout << "q1 3rd pop() : " << q1.pop() << std::endl;
	
	//pop(&q2);
	
	q2.push(900);
	q2.push(800);
	q2.push(700);
	
	std::cout << "q2 1st pop() : " << q2.pop() << std::endl;
	std::cout << "q2 2nd pop() : " << q2.pop() << std::endl;
	std::cout << "q2 3rd pop() : " << q2.pop() << std::endl;
	
	return 0;
}
