#include <iostream>

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void swap3(int &ra, int &rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int a, b;
	a = 100;
	b = 200;
	
	std::cout << "swap\na : " << a << "\tb : " << b << std::endl;
	swap(a, b);
	
	swap2(&a, &b);
	std::cout << "swap2 using ptr\na : " << a << "\tb : " << b << std::endl;
	
	swap3(a, b);
	std::cout << "swap3 using ref\na : " << a << "\tb : " << b << std::endl;
	
	return 0;
}
