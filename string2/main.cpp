#include <iostream>
#include "string.h"

int main()
{
	String s1;
	String s2 = "just the way you are";		// String s2("...");
	String s3 = s2;							// String s3(s2);
	
	s1 = s2 = s2;
	
	if (s1 == s2) {
		std::cout << "s1 and s2 are equal" << std::endl;
	} else {
		std::cout << "s1 and s2 are not equal" << std::endl;
	}
	
	String s4 = " - billy joel";
	s1 = s2 + s4;
	
	s4 = "wonderful tonight";		// String tmp("w..."); s4.operator=(tmp); tmp.~String();
	//s4 = s4.c_str();
	
	//std::cout << "s1 : " << s1.c_str() /*시작 주소값*/ << std::endl;
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	std::cout << "s4 : " << s4 << std::endl;
	
	std::cout << "s1 len: " << s1.size() << std::endl;
	
	return 0;
}
