//#include <cstdio>
#include <iostream>
#include "stack.h"

int main()
{
	Stack s1(100), s2(10);		// initStack 대신 생성자를 통해 한번에
	
	//s1.initStack(100);
	//s2.initStack(100);
	
	s1.push(100);
	s1.push(200);
	s1.push(300);
	
	
	//printf("s1 1st pop(): %d\n", s1.pop());
	//std::cout << "s1 1st pop() : ";
	//std::cout << s1.pop();
	//std::cout << std::endl;		// \n
	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	s2.push(900);
	s2.push(800);
	s2.push(700);
	
	std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
	std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
	std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;
	
	//s1.cleanupStack();
	//s2.cleanupStack();
	
	return 0;
}
