#pragma once
#include <iostream>
#include "Math.h"

class ConsoleScreen
{
public:
	// 생성자를 만든다는것은
	// 내가 만든 생성자 형식으로만 생성해라.
	ConsoleScreen(char _BaseChar);
	void PrintScreen();
	void ClearScreen();
	void SetPixel(const int2& _Position, char _Char);
	void SetPixel(int _X, int _Y, char _Char);

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	char BaseCh = ' ';
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
};
