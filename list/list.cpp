#include <iostream>
#include <cassert>
#include "list.h"

std::ostream& operator<<(std::ostream& out, const List& rhs)
{
	//return rhs.print(out, " -> ");
	return rhs.print(out);
}

/*
static Node *createNode(int data, Node *next)
{
	Node *p = new Node;
	assert(p);
	p->data = data;
	p->next = next;
	
	return p;	// return the address of the node created (reason for Node type func)
}
*/

List::List()
{
	ptr_ = new Node;
	assert(ptr_);
	//ptr_->data = ???;
	ptr_->next = NULL;
}

List::~List()
{
	Node *ptr = ptr_;
	while(ptr) {
		Node *temp = ptr;
		ptr = ptr->next;
		delete temp;
	}
}

std::ostream& List::print(std::ostream& out, const std::string& delim) const
{
	Node *ptr = ptr_->next;
	//std::cout<< "[";
	
	while(ptr) {
		out << ptr->data;
		out << ((ptr->next) ? delim : "");
		ptr = ptr->next;
	}
	return out;
}

void List::insertFirst(int data)
{
	Node *p = new Node;
	assert(p);
	
	p->data = data;
	p->next = ptr_->next;	// dummy node's next
	ptr_->next = p;
}

void List::insert(int prevData, int data)
{
	Node *ptr = ptr_->next;	// points after dummy. ptr is local, ptr_ is parsed from 
	while(ptr) {
		if (ptr->data == prevData) {
			break;
		}
		ptr = ptr->next;
	}
	
	if (ptr) {
		Node *p = new Node;
		assert(p);
		
		p->data = data;
		p->next = ptr->next;
		ptr->next = p;
	}
}

void List::remove(int data)
{
	Node *ptr = ptr_->next;
	Node *ptr2 = ptr_;
	
	while(ptr) {
	if (ptr->data == data) {
		break;
	}
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	
	if (ptr) {
		ptr2->next = ptr->next;
		delete ptr;
	}
}
