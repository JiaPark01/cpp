#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

struct Node {
	int data;
	Node *next;
	// + 6 func
};


class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);

private:
	Node *ptr_;
	
	std::ostream& print(std::ostream& out, const std::string& delim = ", ") const;
	
	List(const List&);				// prevent copy
	List& operator=(const List&);	// prevent 
	
public:
	List();
	~List();

	void insertFirst(int data);
	void insert(int prevData, int data);
	void remove(int data);
};


#endif
