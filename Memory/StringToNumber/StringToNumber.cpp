// StringToNumber.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


//글자 개수를 알아내야 합니다.
//StringCount();
// * 10 을 써야합니다.
// / 10 써야합니다.
// for문을 사용해야합니다.
// 예외처리 안쓴다.

int MySquare(int Num);



int StringCount(const char* const _Ptr) {
	int Count = 0;
	while (_Ptr[Count]) {
		++Count;
	}
	return Count;
}

int SizeofInt(int Num) { //int size

	int Index = 0;
	while (Num) {
		++Index;
		Num /= 10;
	}
	return Index;
}

int GetValue(int Num, int Index) {//그 값의 나머지 알기
	while (Index--) {
		Num /= 10;
	}
	return Num;
}

int FirstNum(int Num, int Index)// 그 값의 첫 번째 수 알기
{
	while (Index--) {
		Num *= 10;
	}
	return Num;
}

/*
* 값을 가져온다.
* 가져온 값의 나머지를 구한다.
* 그 나머지를 원본에서 뺀다.
* 그리고
*/


void NumberToString(int Number, char* _Ptr) {
	int Temp = 0;
	int Size1 = SizeofInt(Number);//그 수의 크기
	int Size2 = Size1;
	while (Size1--) {
		int First = GetValue(Number - Temp, Size1); // 그 수의 제일 앞의 수
		int GetValue = FirstNum(First, Size1); //그 값의 원본 첫 번째 수
		_Ptr[Size2 - Size1 - 1] = First + '0';
		Temp += GetValue;
	}

}

int MySquare(int Num) {
	int Temp = 1;
	while (--Num) {
		Temp *= 10;
	}
	return Temp;
}

int MyStringToNumber(const char* const _NumberString) {
	int Count1 = StringCount(_NumberString);
	int Count2 = Count1;
	int Result = 0;
	while (Count1) {
		Result += (_NumberString[Count2 - Count1] - '0') * MySquare(Count1);
		Count1 -= 1;
	}

	return Result;
}

int StringToNumber(const char* const _NumberString) {
	int Num = 0;
	int Count = StringCount(_NumberString);

	for (int i = 0; i <= Count - 1; ++i) {
		int Temp = 1; // 10의 몇 승을 저장할 변수
		int j = Count - 1 - i;  // 10의 몇 승?
		while (j--) {
			Temp *= 10;
		}
		Num += (_NumberString[i] - '0') * Temp;
	}
	return Num;
}

int main()
{
	char Ch[10] = "1234";

	char Arr[100] = {};

	int Num = 100;


	NumberToString(1234, Arr);
	//int Result1 = StringToNumber(Ch);
	//int Result2 = MyStringToNumber(Ch);
}
