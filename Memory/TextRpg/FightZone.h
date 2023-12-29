#pragma once
#include "ZoneBase.h"
#include "Monster.h"

class FightZone : public ZoneBase
{
public:
	FightZone();

	// ����� ���ö������� ����
	// ���漱��
	// �÷��̾� ����� ���⿡ �����ϱ� �Ⱦ.
	void In(class Player& _Player);

private:
	Monster NewMonster = Monster();
	Monster EliteMonster = Monster(150,15,30,20);
	// �ѹ��� ����
	// ����� ������ ������ �����ؾ� �մϴ�.
	bool FightLogic(FightUnit& _Left, FightUnit& _Right, FightUnit& _Top, FightUnit& _Bot);
};

