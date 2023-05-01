#include <iostream>
#include "complex.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	Complex c1;
	Complex c2(3.0);		// Complex c2 = 3.0;
	Complex c3(3.0, 4.0);
	Complex c4 = c3;		// Complex c4(c3);
	
	c1 = c3;
	c2.real(c3.real());
	c2.imag(c3.imag());
	
	Complex *p1 = &c1;
	const Complex c5(4.0, 5.0);
	const Complex *p2 = &c5;
	
	// 멤버함수가 c5에 접근하는데, 값ㅇ르 바꾸는지 읽기 전용인지 알 수 없음
	// 따라서, 읽기용 함수여도 const에 접근 불가능
	// 접근이 가능하게 하고 싶다면 함수뒤에 const 붙이기
	
	c1.real(c5.real());
	c1.imag(c5.imag());
	
	if (c1 == c2) {
		cout << "c1 and c2 are equal" << endl;
	} else {
		cout << "c1 and c2 are not equal" << endl;
	}
	
	c1 += c2;				// c1 += c2 += c3; daisy chain X due to const
	c1 = c2 + c3;
	
	++c1;
	c1++;
	
	String s = c3;			// (3.0, 4.0i)
	
	cout << "c1 : " << c1 << endl;
	cout << "c2 : " << c2 << endl;
	cout << "c3 : " << c3 << endl;
	cout << "c4 : " << c4 << endl;
	cout << "c5 : " << c5 << endl;
	
	cout << "s : " << s << endl;
	
	cout << "input complex : ";
	Complex c6;
	cin >> c6;
	cout << "c6: " << c6 << endl;
	
	return 0;
}
