#pragma once
#include "NameUnit.h"

class StatusUnit : public NameUnit
{
public:
	virtual void StatusRender();
	virtual inline int GetMinAtt() const {
		return MinAtt;
	}
	virtual inline int GetMaxAtt() const {
		return MaxAtt;
	}

	virtual inline int DropGold() const {
		return Gold;
	}

	virtual inline int GetHp() const {
		return Hp;
	}

	virtual inline void SetHp(int _Hp) {
		Hp = _Hp;
	}

protected:
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
};

