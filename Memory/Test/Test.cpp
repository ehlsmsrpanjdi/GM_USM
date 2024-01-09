// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <ConsoleEngine/EngineDebug.h>
#include <ConsoleEngine/EngineDebug.h>


class IntArray
{
	// private: 디폴트 접근제한 지정자
public:
	// 디폴트 생성자
	IntArray(int _Size)
	{
		ReSize(_Size);
	}

	// 디폴트 복사 생성자
	IntArray(const IntArray& _Other)
	{
		ReSize(_Other.NumValue);

		NumValue = _Other.NumValue;
		for (int i = 0; i < NumValue; ++i) {
			if (nullptr != _Other.ArrPtr) {
				ArrPtr[i] = _Other.ArrPtr[i];
			}
		}
	}
	// 디폴트 소멸자
	~IntArray()
	{
		Release();
	}
	// 디폴트 대입연산자
	void operator=(const IntArray& _Other)
	{
		NumValue = _Other.NumValue;
		for (int i = 0; i < NumValue; ++i) {
			ArrPtr[i] = _Other.ArrPtr[i];
		}
	}

	int& operator[](int _Count)
	{
		return ArrPtr[_Count];
	}

	int& Test(int _Count)
	{
		return ArrPtr[_Count];
	}

	int Num()
	{
		return NumValue;
	}

	void ReSize(int _Size)
	{
		if (0 >= _Size)
		{
			MsgBoxAssert("배열의 크기가 0일수 없습니다");
		}

		NumValue = _Size;

		if (nullptr != ArrPtr)
		{
			Release();
		}

		ArrPtr = new int[_Size];
	}

	void Release()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int NumValue = 0;
	int* ArrPtr = nullptr;
};




int main()
{
	LeckCheck;

	int arr[3] = {};
	arr[5] = 30;


	{
		IntArray NewArray0 = IntArray(5);
		IntArray NewArray1 = IntArray(5);

		NewArray0 = NewArray1;

		NewArray0.~IntArray();
		NewArray1.~IntArray();
	}

	{
		IntArray NewArray0 = IntArray(5);
		IntArray NewArray1 = IntArray(NewArray0);
	}

	// 내가 만든 클래스이기 때문에
	// 배열이 아니었기 때문에
	// 배열의 기능들을 해결해줘야 한다.

	// 1. 대입이 안된다. => 해결
	// 2. 크기를 동적으로 바꿀수 없다.
	// 3. 그 크기를 알수도 없다. 알수는 있는데 불편해

	// NewArray0.~IntArray();
}
