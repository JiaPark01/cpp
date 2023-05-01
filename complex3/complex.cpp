#include <iostream>		// h에 있어서 안 써도 됨
#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs)
{
	out << "(" << rhs.re << ", " << rhs.im << "i)";
	
	return out;
	// 지역 변수가 아닌 인자로 넘어온 cout을 쓰므로 aliasing 넘기기 가능
	// operator는 Complex의 클래스 멤버가 아니라 전역 함수이므로 private의 re, im 접근 불가. 따라서 friend로 클래스 안에 넣어주거나, public의 real(), imag()를 사용. 근데 후자는 const라 변경 안 됨???
}

Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

Complex::Complex(const Complex& rhs)
{
	this->re = rhs.re;
	this->im = rhs.im;
}

/*	// 소멸자가 없으면 컴파일러가 알아서 빈 내용의 소멸자를 만들어줌
Complex::~Complex()
{
	
}
*/

Complex& Complex::operator=(const Complex& rhs)
{
	if (this != &rhs) {
		this->re = rhs.re;
		this->im = rhs.im;
	}
	return *this;	// 자신의 값이 바뀌었으므로 자기 자신이 가리키는 객체가 리턴돼야함
}

bool Complex::operator==(const Complex& rhs)
{
	return (this->re == rhs.re && this->im == rhs.im);
}

bool Complex::operator!=(const Complex& rhs)
{
	return !(this->operator==(rhs));
}

// 결과값은 주소가 아니라 Complex 클래스의 값
// 바뀌지 않을 값이므로 const. 포인터 아님
const Complex Complex::operator+(const Complex& rhs)
{
	Complex result(this->re + rhs.re, this->im + rhs.im);
	return result;
}

const Complex Complex::operator-(const Complex& rhs)
{
	Complex result(this->re - rhs.re, this->im - rhs.im);
	return result;
}

const Complex Complex::operator*(const Complex& rhs)
{
	// real = re*re - im*im
	// imag = re*im + im*re
	Complex result((this->re * rhs.re - this->im * rhs.im), (this->re * rhs.im + this->im * rhs.re));
	return result;
}

const Complex Complex::operator/(const Complex& rhs)
{
	// real = re*re + im*im
	// imag = re*im + im*re
	// divide number (real, imag) by den (divisor re*re + divisor im*im)
	Complex num((this->re * rhs.re + this->im * rhs.im), (this->re * rhs.im + this->im * rhs.re));
	double den = rhs.re*rhs.re + rhs.im*rhs.im;
	Complex result(num.re/den, num.im/den);
	return result;
}

double Complex::real()
{
	return this->re;
}

double Complex::imag()
{
	return this->im;
}

void Complex::real(double re)
{
	this->re = re;
}

void Complex::imag(double im)
{
	this->im = im;
}
