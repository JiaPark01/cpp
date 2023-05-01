#include <iostream>
#include "complex.h"

int main()
{
	Complex c1(3.0, 2.0);	// (3.0 + 4.0i)
	Complex c2 = 3.0;
	Complex c3;				// (0.0 + 0.0i)
	
	Complex c4 = c1;		// Complex c4(c1);
	
	Complex c5;
	Complex c6;
	
	c3 = c1;				// c3.operator=(c1) or operator=(c3, c1) 으로 자동 compile
	c3 = c2 = c1 = c1;		// 식의 결과값은 c3
	c3 = 1.0;
	
	c3 = c1 + c2;			// c3.operator=(r1 + r2); or c3.operator=(c1.operator+(c2)); 
	c3 = c1 - c2;
	
	c2.real(1.0);
	c2.imag(7.0);
	
	c5 = c1 * c2;
	c6 = c1 / c2;
	
	if (c1 == c3) {			// c1.operator==(c3) or operator==(c1, c3)
		std::cout << "c1 and c3 are equal" << std::endl;
	} else {
		std::cout << "c1 and c3 are not equal" << std::endl;
	}
	
	/*
	std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
	std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
	std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
	std::cout << "c5 = c1*c2 : (" << c5.real() << ", " << c5.imag() << "i)" << std::endl;
	std::cout << "c6 = c1/c2 : (" << c6.real() << ", " << c6.imag() << "i)" << std::endl;
	*/
	
	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
	std::cout << "c4 : " << c4 << std::endl;
	std::cout << "c5 = c1*c2 : " << c5 << std::endl;
	std::cout << "c6 = c1/c2 : " << c6 << std::endl;

	return 0;
}
