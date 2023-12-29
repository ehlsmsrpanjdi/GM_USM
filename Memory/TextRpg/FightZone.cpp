#include "FightZone.h"
#include <conio.h>
#include <iostream>
#include "Player.h"

FightZone::FightZone()
{
	NewMonster.SetName("Monster");
	EliteMonster.SetName("EliteMonster");
}

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		
		_getch();
		return true;
	}


	{
		int Input = _getch();
	}

	system("cls");
	_First.DamageLogic(_Second);
	_Top.StatusRender();
	_Bot.StatusRender();
	_First.DamageRender();
	_Second.DamageRender();
	if (true == _First.IsDeath())
	{
		printf_s("���� ���\n");
		_getch();
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::In(Player& _Player)
{
	NewMonster.SetHp();
	EliteMonster.SetHp(150);
	FightUnit* Ptr;
	if (rand() % 2) {
		Ptr = &NewMonster;
	}
	else {
		Ptr = &EliteMonster;
	}

	while (true)
	{
		_Player.StatusRender();
		Ptr->StatusRender();

		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;

		if (_Player.GetRandomSpeed() >= Ptr->GetRandomSpeed())
		{
			printf_s("�÷��̾��� ����\n");
			IsEnd = FightLogic(_Player, *Ptr, _Player, *Ptr);
		}
		else 
		{
			printf_s("������ ����\n");
			IsEnd = FightLogic(*Ptr, _Player, _Player, *Ptr);
		}

			if (true == IsEnd)
			{
				_Player.SetGold(Ptr->DropGold() + _Player.GetGold());
				return;
			}
	}

}