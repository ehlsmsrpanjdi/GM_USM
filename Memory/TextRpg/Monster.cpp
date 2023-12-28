#include "Monster.h"
#include "MyMath.h"
int Monster::GetGold() const
{
	return rand() % Gold;
}
