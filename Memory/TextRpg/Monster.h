#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:

	inline void SetHp() {
		Hp = 100;
	}

	inline int DropGold() const override {
		return Gold;
	}
protected:
	int Gold = 10;
};

