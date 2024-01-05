// 073_Define.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <assert.h>
#include <Windows.h>

// #include "파일명" <= 파일치환
// <= 주석은 메모기능

// 코드치환 + 전처리정의

// 코드치환 디파인
#define TEN 10

// 디파인 매크로 함수라고 합니다.
// 이것도 치환.
// 뒤처진 문법 많이 사용하면 안되는 문법으로 통합니다.
// inline도 생겼고. 
#define PLUS(Value) Value + Value

#define MUL(Value) Value * Value

#define MYTEXT = "AAAAAAAAAA"

// 아무것도 선언하지 않아도 되고
#define MYTEXT2 MYTEXT

#define BOOM assert(false);

#define MsgAssert(TEXT) MessageBoxA(nullptr, TEXT, "치명적 에러", MB_OK); assert(false);

int main()
{
    int ScreenSize = 0;

    if (0 >= ScreenSize)
    {
        MsgAssert("화면 크기가 0입니다");
    }

    char Arr[100] MYTEXT2;

    // int Value = TEN;

    // int Value = PLUS(20);

    int Value = 20 + 20 * 20 + 20;

    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
