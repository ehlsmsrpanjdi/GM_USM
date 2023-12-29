#pragma once
#include "NameUnit.h"

class Weapon : public NameUnit
{
public:
	inline int GetAtt() const
	{
		return Att + GetEquipUp();
	}

	inline void SetAtt(int _Att) 
	{
		Att = _Att;
	}

	inline int GetEquipUp() const {
		return EquipUp;
	}

	inline void SetEquipUp(int _EquipUp) {
		EquipUp = _EquipUp;
	}

	int Upgrade() const;

	void UpgradeResult();

private:
	int EquipUp = 0;
	int Att;
};

