#include "FightZone.h"
#include <conio.h>
#include <iostream>

bool FightZone::FightLogic(FightUnit& _First, FightUnit& _Second, FightUnit& _Top, FightUnit& _Bot)
{
	{
		int Input = _getch();
	}

	system("cls");
	_Second.DamageLogic(_First); //second가 맞는 친구  
	_Top.StatusRender();		//fisrt가 때린 친구
	_Bot.StatusRender();
	_First.DamageRender();
	if (true == _Second.IsDeath())
	{
		printf_s("게임 종료\n");
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
		printf_s("게임 종료\n");
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


		// 선공 후공이 결정 나고
		// 조건에 따라서

		bool IsEnd = false;

		if(_Player.GetSpeed() >= NewMonster.GetSpeed()){
			printf_s("플레이어의 선공");
			IsEnd = FightLogic(_Player, NewMonster, _Player, NewMonster);
		}
		else {
			printf_s("몬스터의 선공");
			IsEnd = FightLogic(NewMonster, _Player, NewMonster, _Player);
		}

			if (true == IsEnd)
			{
				return;
			}
	}

}