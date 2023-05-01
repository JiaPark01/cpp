#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include "string.h"
// header 파일에서는 using 쓰면 안 됨
class Complex {
friend std::ostream& operator << (std::ostream& out, const Complex& rhs);
friend std::istream& operator >> (std::istream& in, Complex& rhs);

private:
	double re_;
	double im_;
	
public:
	Complex(double re = 0.0, double im = 0.0);
	
	const Complex& operator+=(const Complex& rhs);
	// -+, *=, /= not implemented
	
	bool operator==(const Complex& rhs) const;
	// !=, >, <, >=, <= not impl
	
	const Complex operator+(const Complex& rhs) const;	// returns local var, can't use &
	// -, *, / not impl
	
	const Complex& operator++();	// prefix
	const Complex operator++(int );	// postfix - meaningless int par to differentiate
	
	operator String() const;		// typecasting
	
	double real() const;
	double imag() const;
	
	void real(double re);
	void imag(double im);
	
	// ???

};

#ifdef INLINE		// cmd에서 compile 할 때 g++ -c complex.cpp -DINLINE 같이 써줘야 함
#include "complex.inl"
#endif
	///////////////
	// from .cpp //
	///////////////


#endif
