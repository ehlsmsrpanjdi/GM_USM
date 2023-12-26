#pragma once

#include "Math.h"
#include <iostream>
#include <conio.h>


const int2 Left = { -1, 0 };
const int2 Right = { 1, 0 };
const int2 Up = { 0, -1 };
const int2 Down = { 0, 1 };

// ���������� ������ ���þ���
// �̸��� ���� �ִٸ� �װ��� ����� �� �ִ�.
const int ScreenX = 20;
const int ScreenY = 12;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;



class Player
{
public:
	Player();

	Player(const int2& _StartPos, char _RenderChar);

	// inline�� �����Ϸ��� �Լ��� �����ϰ�
	// �� ��ġ�� ġȯ���� ������.
	int2 GetPos();

		char GetRenderChar();

	void Update();


	void SetBulletFire(bool* _IsFire);

private:



	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	bool* IsFire = nullptr;
};