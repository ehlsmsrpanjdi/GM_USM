#include "FightUnit.h"
#include <iostream>

FightUnit::FightUnit()
{
}

int FightUnit::GetRandomAtt() 
{
	// Hp = 500;
	// 39212312 0~10
	int Damage = rand() % ((MaxAtt - MinAtt) + 1);
	CurDamage = MinAtt + Damage;
	return MinAtt + Damage;
}

int FightUnit::GetRandomSpeed() const
{
	return rand() % (Speed + 1);
}

void FightUnit::DamageLogic(FightUnit& _Unit)
{
	SetHp(GetHp() - _Unit.GetRandomAtt());

	if (0 > GetHp())
	{
		SetHp(0);
	}
}

void FightUnit::DamageRender()
{
	printf_s("%s �� %d�� ���ݷ����� �����߽��ϴ�.\n", Name, CurDamage);
}