#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee {
private:
	int id_;
	String name_;
	const Employee *pManager_;
	//
	
	// to prevent from auto generating the following by compiler
	Employee(const Employee& rhs);
	Employee& operator=(const Employee& rhs);
	
public:
	//Employee *operator&() { return this; }
	//const Employee *operator&() const { return this; }
	
	Employee(int id, String name, const Employee *pManager);
	//~Employee() { }
	
	int getId() const;
	String getName() const;
	const Employee *getManager() const;
	
	bool isManager() const;
	
	void setManager(const Employee *pManager);
};

#endif
