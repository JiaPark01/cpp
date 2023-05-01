#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;
	double im;

public:
	Complex();							// function overloading
	Complex(double re);				// one-interface multi-method
	Complex(double re, double im);
	
	~Complex();
	
	double real();	// get func
	double imag();
	
	void real(double re);		// set func
	void imag(double im);
	
	
};

#endif
