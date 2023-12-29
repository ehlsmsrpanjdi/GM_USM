#pragma once
#include "FightUnit.h"

class Monster : public FightUnit
{
public:
	Monster();
	Monster(int _Hp, int _MinAtt, int _MaxAtt, int _Gold);

	inline void SetHp() {
		Hp = 100;
	}

	inline void SetHp(int _Hp) {
		Hp = _Hp;
	}

	inline int DropGold() const override {
		return Gold;
	}

protected:
	int Gold = 10;
};

