#ifndef ARRAY_H
#define ARRAY_H

//extern const int ARRAY_SIZE;	// define과 다르게 전역 변수는 컴파일 시간에 실행되므로 타입 체킹이 가능해짐. 더 엄격하게.

class Array {
private:
	static const int ARRAY_SIZE;	// 클래스와 관련 되어있으므로 여기에 static으로
	int *pArr_;
	int size_;

public:
	//Array *operator&() {return this; }
	//const Array *operator&() {return this; }

	explicit Array(int size = Array::ARRAY_SIZE);	// static 멤버 접근할 때 클래스 이름:: 붙여줘야 함. 같은 클래스면 생략해도 됨
	Array(const int *pArr, int size);
	Array(const Array& rhs);
	~Array();
	
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	int& operator[](int index);
	const int& operator[](int index) const;
	
	int size() const;
};

#endif
