#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

void FightUnit::DamageLogic(FightUnit& _Unit)
{
	Hp -= _Unit.GetDamage();
}

void FightUnit::DamageRender()
{
	printf_s("%s 가 %d의 공격력으로 공격했습니다.\n", Name, GetpresentDamage());
}