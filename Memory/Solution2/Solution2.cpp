// Solution2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int _Value0, int _Value1, int _Value2, int _Value3) {
	int* Addresses[4] = { &_Value0,&_Value1 ,&_Value2 ,&_Value3 };
	__int64 Address0 = reinterpret_cast<__int64>(Addresses[0]);
	__int64 Address1 = reinterpret_cast<__int64>(Addresses[1]);
	__int64 Address2 = reinterpret_cast<__int64>(Addresses[2]);
	__int64 Address3 = reinterpret_cast<__int64>(Addresses[3]);
}

int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	Test(a, b, c, d);

}

