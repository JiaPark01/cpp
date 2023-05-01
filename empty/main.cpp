#include <iostream>
#include "empty.h"

int main()
{
	Empty e1;
	Empty e2 = e1;			// 복사 생성자. Empty e2(e1);
	
	e1 = e2;				// 치환
	
	Empty *p = &e1;			// e1.operator&();
	
	const Empty e3 = e1;
	const Empty *p2 = &e3;	// e3.operator&();
	
	return 0;
}
