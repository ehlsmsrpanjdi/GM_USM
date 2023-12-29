#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// 이런 경우에 public으로 한다.
	// 값으로 들고 있는 경우에는.
	// 보통 이런다.
	// 포인터로 해야 합니다.

	// 내가 만들려는 컨텐츠에 따라서
	// 이걸 값으로 해야할지
	// 포인터로 해야할지.

	// 보통 존재하거나 존재하지 않을 가능성이 있다면 => 포인터
	// 절대로 사라지지 않아야 하면 => 값형
	// 지금은 동적할당을 배우지 않았기 때문에 
	Weapon Weapon;

	inline int GetHp() const override {
		return Hp;
	}

	inline void SetHp(int _Hp) override {
		Hp = _Hp;
	}

	inline int GetGold() const{
		return Gold;
	}

	inline void SetGold(int _Gold) {
		Gold = _Gold;
	}

	inline void Heal() {
		SetHp(GetMaxHp());
		SetGold(GetGold() - 3);
	}

	void StatusRender();
	inline int GetMaxHp() const {
		return MaxHp;
	}

	inline int GetMinAtt() const override {
		return MinAtt + Weapon.GetAtt();
	}
	inline int GetMaxAtt() const override {
		return MaxAtt + Weapon.GetAtt();
	}


protected:
	int GetRandomAtt() override;
	int MaxHp = 100;
	int Hp = 100;
	int Gold = 100;
	int Exp = 0;
	int MaxExp = 100;
};

