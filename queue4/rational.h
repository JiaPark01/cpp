#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "string.h"

class Rational{
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
	int num_;
	int den_;
	
	void abbreviate();		// helper func

public:
	//Rational(const Rational& rhs) { /* memberwise copy */ }
	//~Rational() { }
	//Rational& operator=(const Rational& rhs) { /*memberwise copy*/ return *this; }
	//Rational * operator&() { return this; }
	//const Rational * operator&() const { return this;	//상수 객체 참조하는 포인터
	
	Rational(int num = 0, int den = 1);
	
	Rational& operator=(const Rational& rhs);
	
	const Rational& operator+=(const Rational& rhs);
	const Rational& operator-=(const Rational& rhs);
	const Rational& operator*=(const Rational& rhs);
	const Rational& operator/=(const Rational& rhs);
	
	// &=, |= X
	
	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	
	
	// >, <, >=, <=
	
	const Rational operator+(const Rational& rhs) const;
	const Rational operator-(const Rational& rhs) const;
	const Rational operator*(const Rational& rhs) const;
	const Rational operator/(const Rational& rhs) const;
	
	// % X
	
	const Rational& operator++();
	const Rational operator++(int );
	const Rational& operator--();
	const Rational operator--(int );
	// ++, -- X
	
	operator String() const;
	
	
	int getNum() const;
	int getDen() const;
	/*
	void setNum(int num);
	void setDen(int den);*/
};

#endif
