// 072_Assert.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h> // 이 윈도우 헤더입니다.
                     // 플랫폼 헤더
#include <assert.h> // 윈도우

int main()
{
    // 프로그램을 파괴할수 있는 함수를 말합니다.
    // 일부러 심각한 익셉션을 일으켜서 절대로 벌어지면 안되는 사용법이
    // 사용됐다는것을 알려주는 것입니다.
    // 프로그램을 파괴한다. 

    // 사용법만 배울것이다.
    // 사실 앞으로 영원히 이렇게 쓸거다.
    MessageBoxA(nullptr, "X 크기가 0입니다", "치명적 에러", MB_OK);
    assert(false);

    // std::cout << "Hello World!\n";
}
