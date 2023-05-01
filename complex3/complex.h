#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);
//cout이 내부적으로 바뀌므로 첫번째 인자에선 const 쓰면 안 됨. 전역함수를 클래스의 friend로

private:
	double re;
	double im;

public:
	Complex(double re = 0.0, double im = 0.0);	// ordinary const.	 default argument
	Complex(const Complex& rhs);					// copy const
	~Complex();									// destructor
	
	//new. rhs = reference
	Complex& operator=(const Complex& rhs);		// Complex로 넘기므로 참조로 보냄 (복사 중복 방지 위해?)
	bool operator==(const Complex& rhs);
	bool operator!=(const Complex& rhs);
	
	const Complex operator+(const Complex& rhs);
	const Complex operator-(const Complex& rhs);
	const Complex operator*(const Complex& rhs);
	const Complex operator/(const Complex& rhs);
	
	double real();
	double imag();
	void real(double re);
	void imag(double im);
};

#endif
