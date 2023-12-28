#pragma once
#include "ConsoleObject.h"

#include <conio.h>

class Player : public ConsoleObject
{
public:
	Player();

	Player(const int2& _StartPos, char _RenderChar);

	// inline은 컴파일러가 함수를 삭제하고
	// 그 위치에 치환시켜 버린다.
	int2 GetPos();

	char GetRenderChar();

	void Update();

	void SetBulletFire(bool* _IsFire);

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};
