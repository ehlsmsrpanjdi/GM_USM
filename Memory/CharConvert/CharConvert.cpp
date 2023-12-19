// CharConvert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int CharConvert(char* _String, char _PrevCh, char _NextCh) {

	int Count = 0;  //Return용도의 총 몇개 바꿨는지
	int Index = 0;  //While문 돌리기 용도

	while (_String[Index]) {
		if (_String[Index] == _PrevCh) {
			_String[Index] = _NextCh;
			++Count;
		}
		++Index;
	}


	return Count;
}





int main()
{
	char Arr[30] = "aabbccddeeffgg";
	const char* ar = "asdf";
	int vv = 8;

	__int64 pAr = reinterpret_cast<__int64>(ar);
	__int64 pArr = reinterpret_cast<__int64>(Arr);
	__int64 pv = reinterpret_cast<__int64>(&vv);
	//int a = CharConvert(Arr, 'b', 'd');
}
