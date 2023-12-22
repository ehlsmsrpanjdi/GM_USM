// myclass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class MyInt {
public:

	MyInt() {

	}

	MyInt(int _Value)
		:Value(_Value)
	{

	}

	MyInt operator-(const MyInt& _Other) {

		return Value - _Other.Value;
	}

private:
	int Value;


};

void test(int& asdf) {
	int a = asdf;
}

int main()
{
	int* a;
	test(*a);


}
