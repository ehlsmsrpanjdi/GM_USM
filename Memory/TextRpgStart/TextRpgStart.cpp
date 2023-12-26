// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "Player.h"
#include "Galaga.h"
#include "Console.h"
// 0. 메모리

// 문제점.
// 1. 코드 정리가 안된다.
// 2. 반복적 코드가 많다.
// 3. 메모리를 동적으로 이용이 불가능하다. 
//    불가능하다. (화면의 크기 총알의 개수)




class Bullet
{
public:
	Bullet(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	bool& GetIsFireRef()
	{
		return IsFire;
	}

	inline int2 GetPos()
	{
		return Pos;
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

private:
	bool IsFire = false;
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};

// 함수의 실행 메모리는 고정되어 있어야 한다.
// => exe파일에 적혀있다. main함수는 100바이트 사용한다.
// 한번 컴파일이 되고나면 절대로 바뀔수 없다
int main()
{
	// 과제 1
	// 화면 외곽을 벽으로 채워라
	// 플레이어가 벽 바깥으로 못나가게 만들어라.
	// [#][#][#][#][#][0]
	// [#][*][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]

	// 과제 2
	// 플레이어가 키를 누르면
	// [#][#][#][#][#][0]
	// [#][I][*][*][#][0]
	// [#][*][@][*][#][0]
	// [#][*][*][*][#][0]
	// [#][#][#][#][#][0]


	// 변수가 들어갈수 없어요.
	ConsoleScreen NewScreen = ConsoleScreen('*');
	Galaga NewGalaga = Galaga();

	// Player가 bool& _OtherFire; 총알이 무조건 먼저 만들어져야 한다.
	Bullet NewBullet = Bullet({ 0,0 }, '^');
	// NewBullet.GetIsFireRef()
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');

	bool& Ref = NewBullet.GetIsFireRef();
	NewPlayer.SetBulletFire(&Ref);

	while (true)
	{
		NewScreen.ClearScreen();
		NewGalaga.GalagaWallDraw(NewScreen);

		int2 Index = NewPlayer.GetPos();
		char Ch = NewPlayer.GetRenderChar();

		NewScreen.SetPixel(Index, Ch);

		if (true == NewBullet.GetIsFireRef())
		{
			NewScreen.SetPixel(NewBullet.GetPos(), NewBullet.GetRenderChar());
		}

		NewScreen.PrintScreen();
		NewPlayer.Update();
	}




}
