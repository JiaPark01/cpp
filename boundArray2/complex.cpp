#include <iostream>
#include <cstdio>
#include "string.h"
#include "complex.h"

std::istream& operator >> (std::istream& in, Complex& rhs)
{
	double re = 0.0;
	double im = 0.0;
	char c = 0;
	
	in >> c;
	if (c == '(') {
		in >> re >> c;
		if (c == ',') in >> im >> c;
		if (c == 'i') in >> c;
		if (c == ')') in.clear(std::ios::failbit);
	} else {
		in.putback(c);
		in >> re;
	}
	if (in) rhs = Complex(re,im);
	return in;
}

std::ostream& operator << (std::ostream& out, const Complex& rhs)
{
	//return out << "(" << rhs.real() << ", " << rhs.imag() << "i)";
	return out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
}

Complex::Complex(double re, double im)
: re_(re), im_(im)	// constructor init. list
{
	//re_ = re;
	//im_ = im;
}

const Complex& Complex::operator+=(const Complex& rhs)
{
	re_ += rhs.re_;
	im_ += rhs.im_;
	
	return *this;
}

bool Complex::operator==(const Complex& rhs) const
{
	return re_ == rhs.re_ && im_ == rhs.im_;
}

const Complex Complex::operator+(const Complex& rhs) const
{
	Complex result(re_ + rhs.re_, im_ + rhs.im_);
	
	return result;
}

const Complex& Complex::operator++()
{
	re_ += 1.0;
	return *this;
}

const Complex Complex::operator++(int )
{
	
	Complex temp(*this);
	re_ += 1.0;
	
	return temp;
}

Complex::operator String() const
{
	char buf[128];
	sprintf(buf, "(%f, %fi)", re_, im_);
	
	String result(buf);
	return result;
}

double Complex::real() const
{
	return re_;
}

double Complex::imag() const
{
	return im_;
}

void Complex::real(double re)
{
	re_ = re;
}

void Complex::imag(double im)
{
	im_ = im;
}
