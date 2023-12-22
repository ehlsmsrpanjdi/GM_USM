// ConsoleGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

class int2
{
	// 보통 이런 수학적 클래스는
	// public으로 맴버변수를 두는 편입니다.
public:
	int X = 0;
	int Y = 0;

	void operator=(const int2& _Other) {
		X = _Other.X;
		Y = _Other.Y;
	}

	int2 operator+(const int2& _Other) {
		X += _Other.X;
		Y += _Other.Y;
	}

	int2 operator-(const int2& _Other) {
		X -= _Other.X;
		Y -= _Other.Y;
	}
};

// 이런걸 정의하는것을 좋아하지는 안습니다.
typedef int2 Pos;

// 전역변수는 영역과 관련없이
// 이름이 위에 있다면 그것을 사용할 수 있다.
const int ScreenX = 20;
const int ScreenY = 10;
const int ScreenXHalf = ScreenX / 2;
const int ScreenYHalf = ScreenY / 2;

class ConsoleScreen
{
public:
	// 생성자를 만든다는것은
	// 내가 만든 생성자 형식으로만 생성해라.
	ConsoleScreen(char _BaseChar)
	{
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]
		// [*][*][*][*][*][0]

		for (int y = 0; y < ScreenY; y++)
		{
			for (int x = 0; x < ScreenX - 1; x++)
			{
				if (x == 0 || y == 0) {
					Arr[y][x] = BaseWall;
				}
				else if (x == ScreenX - 2 || y == ScreenY - 1) {
					Arr[y][x] = BaseWall;
				}
				else {
					Arr[y][x] = _BaseChar;
				}
			}
		}
	}

	void PrintScreen()
	{
		for (int y = 0; y < ScreenY; y++)
		{
			char* Ptr = Arr[y];
			printf_s(Ptr);
			printf_s("\n");
		}
	}

	void ClearScreen()
	{
		system("cls");

		for (int y = 0; y < ScreenY; y++)
		{
			for (int x = 0; x < ScreenX - 1; x++)
			{
				if (Arr[y][x] == BaseBullet) {
					if (y != 0) {
						Arr[y - 1][x] = BaseBullet;
						Arr[y][x] = BaseChar;
						continue;
					}
				}

				if (x == 0 || y == 0) {
					Arr[y][x] = BaseWall;
				}
				else if (x == ScreenX - 2 || y == ScreenY - 1) {
					Arr[y][x] = BaseWall;
				}
				else {
					Arr[y][x] = BaseChar;
				}
			}
		}
	}

	void SetPixel(const int2& _Position, char _Char)
	{
		SetPixel(_Position.X, _Position.Y, _Char);
	}

	void SetPixel(int _X, int _Y, char _Char)
	{
		if (Arr[_Y][_X] == BaseBullet) {
			return;
		}
		Arr[_Y][_X] = _Char;
	}

protected:

private:
	char Arr[ScreenY][ScreenX] = { 0, };
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]
	// [0][0][0][0][0][0]

	char BaseChar = '*';
	char BaseWall = '#';
	char BaseBullet = '|';
};

class Player
{
public:
	Player()
	{
	}

	Player(const int2& _StartPos, char _RenderChar)
		: Pos(_StartPos), RenderChar(_RenderChar)
	{
	}

	// inline은 컴파일러가 함수를 삭제하고
	// 그 위치에 치환시켜 버린다.
	inline int2 GetPos()
	{
		return Pos;
	}

	inline void SetPos(int2 _Pos) {
		SetPos(_Pos.X, _Pos.Y);
	}

	inline void SetPos(int _X, int _Y) {
		SetPosX(_X);
		SetPosY(_Y);
	}

	inline void SetPosX(int _X) {
		if (_X > 0 && _X < ScreenX - 2) {
			Pos.X = _X;
		}
	}

	inline void SetPosY(int _Y) {
		if (_Y > 0 && _Y < ScreenY - 1) {
			Pos.Y = _Y;
		}
	}

	inline char GetRenderChar()
	{
		return RenderChar;
	}

	void Update(ConsoleScreen& _Screen)
	{
		// Pos.X += 1;
		// getch의 리턴값을 확인해서
		// 상하좌우로 움직이게 하세요.

		int Key;
		Key = _getch();

		if (Key == 224) {

			Key = _getch();

			if (72 == Key) {  //위
				SetPosY(GetPos().Y - 1);
			}
			else if (80 == Key) {  //아래
				SetPosY(GetPos().Y + 1);

			}
			else if (75 == Key) {  //왼쪽
				SetPosX(GetPos().X - 1);
			}
			else if (77 == Key) {  //오른쪽
				SetPosX(GetPos().X + 1);
			}
		}
		else if (Key == 32) {
			_Screen.SetPixel({ GetPos().X, GetPos().Y }, '|');
		}
		else {
			if ('w' == Key || 'W' == Key) {  //위
				SetPosY(GetPos().Y - 1);
			}
			else if ('s' == Key || 'S' == Key) {  //아래
				SetPosY(GetPos().Y + 1);

			}
			else if ('a' == Key || 'A' == Key) {  //왼쪽
				SetPosX(GetPos().X - 1);
			}
			else if ('d' == Key || 'D' == Key) {  //오른쪽
				SetPosX(GetPos().X + 1);
			}
		}

	}

private:
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};
//
//class Bullet {
//public:
//	Bullet() {};
//	Bullet(int2 _Pos)
//		:Pos(_Pos)
//	{
//	}
//	Bullet(int _X, int _Y)
//	{
//		Pos.X = _X;
//		Pos.Y = _Y;
//	}
//protected:
//private:
//	int2 Pos = { 0,0 };
//};

// 함수의 실행 메모리는 고정되어 있어야 한다.
// => exe파일에 적혀있다. main함수는 100바이트 사용한다.
// 한번 컴파일이 되고나면 절대로 바뀔수 없다
int main()
{
	// 변수가 들어갈수 없어요.

	ConsoleScreen NewScreen = ConsoleScreen('*');
	Player NewPlayer = Player({ ScreenXHalf, ScreenYHalf }, '@');
	while (true)
	{
		NewScreen.ClearScreen();
		NewScreen.SetPixel(NewPlayer.GetPos(), NewPlayer.GetRenderChar());
		NewScreen.PrintScreen();
		NewPlayer.Update(NewScreen);

	}




}
