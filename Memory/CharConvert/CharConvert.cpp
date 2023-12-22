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
	char ch[2][3] = { 'a','b','c','d','e','f' };

	int arr[3][3] = {1,2,3,4,5,6,7,8,9};


	printf_s("%d", arr[0]);

}
