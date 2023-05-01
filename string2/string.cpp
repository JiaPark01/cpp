#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	//return out << rhs.rep_->str_;
	return out << rhs.c_str();
}

String::String()
{
	rep_ = new StringRep();
	assert(rep_);
	rep_->rc = 1;
}

String::String(const char *s)
{
	rep_ = new StringRep(s);
	rep_->rc = 1;
}

String::String(const String& rhs)
{
	rep_ = rhs.rep_;
	++rep_->rc;
	
}

String::~String()
{
	--rep_->rc;
	if (rep_->rc == 0)
		delete rep_;
}


String& String::operator=(const String& rhs)
{
	if (this != &rhs) {
		--rep_->rc;
		if (rep_->rc == 0)
			delete rep_;
	}
	rep_ = rhs.rep_;
	++rep_->rc;
	
	return *this;
}

/*
String& String::operator=(const char *s)
{
	if (this->str != s) {
		--rep_->rc;
		if (rep_->rc == 0) {
			delete rep_;
		}
		
		rep_ = new StringRep(s);
		rep_->rc = 1;
	}
	
	return *this;
}
*/

bool String::operator==(const String& rhs) const
{
	return strcmp(rep_->str_, rhs.rep_->str_) == 0;
}

const String String::operator+(const String& rhs) const
{
	char *buf = new char[rep_->len_ + rhs.rep_->len_ + 1];
	assert(buf);
	strcpy(buf, rep_->str_);
	strcat(buf, rhs.rep_->str_);

	String result(buf);
	delete [] buf;
	
	return result;
}

const char *String::c_str() const
{
	return rep_->str_;
}

int String::size() const
{
	return rep_->len_;
}
