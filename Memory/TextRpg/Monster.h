#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:
	Monster() {
		Gold = 10;
		SetName("Monster");
	}
	int GetGold() const;
};

