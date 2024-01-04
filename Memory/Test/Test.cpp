// Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <testengine/TestConsoleScreen.h>
#include <..\Memory\TestPhysics\Gravity.h>

int main()
{
	TestConsoleScreen Screen = TestConsoleScreen();
	Screen.test();

	Gravity gravity;
	gravity.Test();
	int a = gravity.F;

	int c = 0;
}


//메모리맵을 직접 그려볼건데 조금 복잡한 할당을 만들거임
