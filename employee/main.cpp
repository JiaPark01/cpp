#include <iostream>
#include "employee.h"

void printEmployee(const Employee *p)
{
	std::cout << p->getId() << ", " << p->getName() << ", ";
	if (p->isManager()) {
		std::cout << "Manager";
	} else {
		std::cout << p->getManager()->getName();
	}
	std::cout << std::endl;
}

int main()
{
	Employee e1(1, "Park Jung Seok", NULL);
	
	// Employee e2;			X
	// Employee e3 = e1;	X
	// e1 = e2;				X
	
	Employee *employees[5];
	employees[0] = new Employee(1, "Park Jung Seok", NULL);
	employees[1] = new Employee(2, "Sung Young Ho", employees[0]);
	employees[2] = new Employee(3, "Sim Sung Suk", employees[0]);
	employees[3] = new Employee(4, "Choi Su Gil", employees[2]);
	employees[4] = new Employee(5, "Kim Young Jin", employees[1]);
	
	for (int i = 0; i < 5; ++i) {
		printEmployee(employees[i]);
	}
	
	for (int i = 0; i < 5; ++i) {
		delete employees[i];		// 어차피 heap에 만들어져서 * 안 씀?
	}
	
	return 0;
}
