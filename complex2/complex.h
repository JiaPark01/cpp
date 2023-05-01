#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;
	double im;

public:
	//Complex();								// default constructor
	//Complex(double re);						// convert constructor
	Complex(double re = 0.0, double im = 0.0);	// ordinary const.	 default argument
	Complex(const Complex &rc);					// copy const
	
	~Complex();									// destructor
	
	//void operator=(Complex c);
	//void operator=(const Complex *pc);
	void operator=(const Complex &rc);
	bool operator==(const Complex &rc);
	
	double real();
	double imag();
	void real(double re);
	void imag(double im);
};

#endif
