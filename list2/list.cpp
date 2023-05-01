#include <iostream>
#include <cassert>
#include "list.h"

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

Node::Node(int data, const Node *next)
//: data_(data), next_( (Node *)next)
: data_(data), next_(const_cast<Node *>(next))
{
	
}

std::ostream& operator<<(std::ostream& out, const List& rhs)
{
	//return rhs.print(out, " -> ");
	return rhs.print(out);
}

List::List()
{
	//ptr_ = createNode(-1, NULL);
	ptr_ = new Node(-1, NULL);
}

List::~List()
{
	Node *ptr = ptr_;
	while(ptr) {
		Node *temp = ptr;
		ptr = ptr->next_;
		delete temp;
	}
}

std::ostream& List::print(std::ostream& out, const std::string& delim) const
{
	Node *ptr = ptr_->next_;
	//std::cout<< "[";
	
	while(ptr) {
		out << ptr->data_;
		out << ((ptr->next_) ? delim : "");
		ptr = ptr->next_;
	}
	return out;
}

void List::insertFirst(int data)
{
	//ptr_->next = createNode(data, ptr_->next);
	ptr_->next_ = new Node(data, ptr_->next_);
}

void List::insert(int prevData, int data)
{
	Node *ptr = ptr_->next_;	// points after dummy. ptr is local, ptr_ is parsed from 
	
	while(ptr) {
		if (ptr->data_ == prevData) {
			break;
		}
		ptr = ptr->next_;
	}
	
	if (ptr) {
		//ptr->next = createNode(data, ptr->next);
		ptr->next_ = new Node(data, ptr->next_);
	}
}

void List::remove(int data)
{
	Node *ptr = ptr_->next_;
	Node *ptr2 = ptr_;
	
	while(ptr) {
	if (ptr->data_ == data) {
		break;
	}
		ptr = ptr->next_;
		ptr2 = ptr2->next_;
	}
	
	if (ptr) {
		ptr2->next_ = ptr->next_;
		delete ptr;
	}
}
