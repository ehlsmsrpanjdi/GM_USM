// StringTrim.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void LeftMoveString(char* _Ptr, int _Start) {
	int Index = _Start;
	while (_Ptr[Index]) {
		if (_Ptr[Index + 1]) {
			_Ptr[Index] = _Ptr[Index + 1];
		}
		++Index;
	}
	_Ptr[Index - 1] = 0;
}

void DeleteChar(char* _Ptr, char _DeleteCh) {

	int Index = 0;//while문용 while

	while (_Ptr[Index]) {

		if (_Ptr[Index] != _DeleteCh) {
			++Index;
		}

		else {
			LeftMoveString(_Ptr, Index);
			continue;
		}
	}
}


int main()
{
	char Arr[100] = "bbaabbaa";
	//char Arr[100] = "a";
	//LeftMoveString(Arr, 0);
	DeleteChar(Arr, 'b');
}
