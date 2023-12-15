// Solution2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void Test(int _Value0, int _Value1, int _Value2, int _Value3,int** Addresses) {

	Addresses[0] = &_Value0;
	Addresses[1] = &_Value1;
	Addresses[2] = &_Value2;
	Addresses[3] = &_Value3;

}

//Addresses는 그냥 배열
//*Addresses는 Addresses의 index 안의 값 **Addresses는 index안의 값의 주소

//**Addresses 인 이유는 그냥 간단하게 Addresses의 내부 값들의 타입이 int*여서 그렇다.
//*int타입의 값의 *를 가져오고 싶으니 당연히 **를 쓰는 것이 맞다.
//만약 Addresses가 타입이 그냥 int[]였다면
// *Addresses만 사용 하여도 Addresses의 값에 참조를 할 수 있다.

int main()
{
	int* Addresses[4];
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	Test(a, b, c, d, Addresses);
	__int64 Address0 = reinterpret_cast<__int64>(Addresses[0]);
	__int64 Address1 = reinterpret_cast<__int64>(Addresses[1]);
	__int64 Address2 = reinterpret_cast<__int64>(Addresses[2]);
	__int64 Address3 = reinterpret_cast<__int64>(Addresses[3]);

}


