#include "Bullet.h"
#include "ConsoleScreen.h"

Bullet::Bullet(const int2& _StartPos, char _RenderChar)
	: Pos(_StartPos), RenderChar(_RenderChar)
{
}

bool& Bullet::GetIsFireRef()
{
	return IsFire;
}

int2 Bullet::GetPos()
{
	return Pos;
}

char Bullet::GetRenderChar()
{
	return RenderChar;
}