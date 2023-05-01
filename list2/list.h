#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

class Node {
friend class List;
private:
	int data_;
	Node *next_;
	
	Node(int data, const Node *next);		// 생성자가 private에 있으므로 List를 통해서만 접근 가능. main에서 생성 불가
	
public:

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
