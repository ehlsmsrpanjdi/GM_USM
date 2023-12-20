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
	int a = 0b0000000001100110;
	char* Ptr = reinterpret_cast<char*>(a);

	Ptr[0];

	Ptr[1];
	Ptr[2];
	Ptr[3];

}
