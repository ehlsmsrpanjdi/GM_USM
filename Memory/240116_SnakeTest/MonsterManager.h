#pragma once
#include "ConsoleEngine/ConsoleUpdater.h"
#include <vector>


class MonsterManager : public ConsoleUpdater 
{
public:

	void Spawn_Monster();
	
	void Update() override;

	static void ResetBody()
	{
		CurMonster = nullptr;

	}
private:
	static std::vector<class Monster*> MonsterList;
public:
	static std::vector<class Monster*>* GetVec() {
		return &MonsterList;
	}
private:
	int CoolTime = 0;
	static class Monster* CurMonster;


};

