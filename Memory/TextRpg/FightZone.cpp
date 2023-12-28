#include "FightZone.h"
#include <conio.h>
#include <iostream>

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First); //second�� �´� ģ��  
	_Top.StatusRender();		//fisrt�� ���� ģ��
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("���� ����\n");
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
		printf_s("���� ����\n");
		return true;
	}
	{
		int Input = _getch();
	}
	system("cls");

	return false;
}

void FightZone::Fight(FightUnit& _Player)
{
	while (true)
	{
		_Player.StatusRender();
		NewMonster.StatusRender();


		// ���� �İ��� ���� ����
		// ���ǿ� ����

		bool IsEnd = false;

		if(_Player.GetSpeed() >= NewMonster.GetSpeed()){
			printf_s("�÷��̾��� ����");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else {
			printf_s("������ ����");
			IsEnd = FightLogic(NewMonster, _Player, NewMonster, _Player);
		}

			if (true == IsEnd)
			{
				return;
			}
	}

}