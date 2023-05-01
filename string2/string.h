#ifndef STRING_H
#define STRING_H
#include <iostream>
#include "stringRep.h"

class String {
friend std::ostream& operator<<(std::ostream& out, const String& rhs);

private:
	StringRep *rep_;
	

public:
	// String *operator() { return this; }
	// const String *operator&() const { return this; }
	
	String();
	String(const char *s);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs);
	//String& operator=(const char *s);
	// +=, *=
	
	bool operator==(const String& rhs) const;
	// !=, >, <, >=, <=
	
	const String operator+(const String& rhs) const;
	// *
	
	// get
	const char *c_str() const;
	int size() const;
	
	// set은 필요 없음. 문자열과 길이 각각의 멤버를 바꿀 수 없으므로
};

#endif
