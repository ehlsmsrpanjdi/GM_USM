// StringContains.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

enum class StringReturn
{
    Equal,
    NotEqual
};

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
    int Index = 0;
    while (_Left[Index] == _Right[Index]) {
        if (_Left[Index++] == 0) {
            return StringReturn::Equal;
        }
    }
    return StringReturn::NotEqual;
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
    int Index1 = 0;
    int Index2 = 0;
    while (_Left[Index1] != 0) {
        _Dest[Index1] = _Left[Index1];
        ++Index1;
    }
    while (_Right[Index2] != 0) {
        _Dest[Index1] = _Right[Index2];
        ++Index1; 
        ++Index2;
    }
    _Dest[Index1] = 0;
    return;
}

int StringContains(const char* const _Dest, const char* const _Find)
{
    int Index1 = 0;
    int Index2 = 0;
    int Count = 0;
    while (_Dest[Index1] != 0) {

        if (_Dest[Index1] != _Find[Index2]) {
            ++Index1;
        }


        while (_Dest[Index1] == _Find[Index2]) {

            ++Index1;
            ++Index2;
            if (_Find[Index2] == 0) {
                ++Count;
                break;
            }
        }
        Index2 = 0;

    }
    return Count;
}

int main()
{

    {
        // 오른쪽과 왼쪽이 같아?
        StringReturn Return = StringEqual("AAAA", "AAAAA");

        int a = 0;

    }

    {
        char Arr[100] = {};
        StringAdd(Arr, "abcdefg", "hijklnm");
        // "cccccddddd"
        int a = 0;
    }

    {
        // int Result = StringContains("ababcccccabab", "ab");

        int Result = StringContains("ababcccccabab", "ab");

        int a = 0;
    }
}

