#include <iostream>
#include "queue.h"
#include "rational.h"

int main()
{
	Queue<int> q1;
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	while (!q1.isEmpty()) {
		std::cout << "q1.pop() : " << q1.pop() << std::endl;
	}
	
	std::cout << std::endl;
	
	Queue<Rational> q2;
	q2.push(Rational(3));
	q2.push(Rational(3, 4));
	q2.push(Rational());
	
	while (!q2.isEmpty()) {
		std::cout << "q2.pop() : " << q2.pop() << std::endl;
	}
	
	// g++ -o testQueue main.o rational.o string.o gcd.o
	return 0;
}
