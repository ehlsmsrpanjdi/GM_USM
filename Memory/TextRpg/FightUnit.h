#pragma once
#include "StatusUnit.h"

class FightUnit : public StatusUnit
{
public:
	FightUnit();

	// Get
	inline bool IsDeath() const
	{
		return Hp <= 0;
	}


	// Fight�� �Լ�
	void DamageLogic(FightUnit& _Unit);

	void DamageRender();

protected:

private:
};
