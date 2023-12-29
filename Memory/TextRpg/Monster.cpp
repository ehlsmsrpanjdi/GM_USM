#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(int _Hp, int _MinAtt, int _MaxAtt, int _Gold)
{
	SetHp(_Hp);
	MinAtt = _MinAtt;
	MaxAtt = _MaxAtt;
	Gold = _Gold;
}

