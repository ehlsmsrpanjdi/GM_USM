#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	// Get
	inline bool IsDeath() const
	{
		return GetHp() <= 0;
	}

	inline int GetMinAtt() const
	{
		return MinAtt;
	}

	virtual int GetRandomAtt();

	inline int GetHp() const override {
		return Hp;
	}

	inline void SetHp(int _Hp) override {
		Hp = _Hp;
	}

	int GetRandomSpeed() const;

	// Fight¿ë ÇÔ¼ö
	void DamageLogic(FightUnit& _Unit);

	void DamageRender();

	//virtual inline int DropGold() const {
	//	return Gold;
	//}

protected:
	int CurDamage = 0;

private:
};
