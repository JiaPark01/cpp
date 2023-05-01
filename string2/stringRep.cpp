#include <cstring>
#include <cassert>
#include "stringRep.h"

StringRep::StringRep()
{
	str_ = new char[1];
	assert(str_);
	str_[0] = '\0';
	len_ = 0;
}

StringRep::StringRep(const char *s)
{
	str_ = new char[strlen(s) + 1];
	assert(str_);
	strcpy(str_, s);
	len_ = strlen(s);
}

StringRep::~StringRep()
{
	delete [] str_;
}


