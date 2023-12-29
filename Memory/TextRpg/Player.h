#pragma once
#include "FightUnit.h"
#include "Weapon.h"

class Player : public FightUnit
{
public:
	Player();

	// �̷� ��쿡 public���� �Ѵ�.
	// ������ ��� �ִ� ��쿡��.
	// ���� �̷���.
	// �����ͷ� �ؾ� �մϴ�.

	// ���� ������� �������� ����
	// �̰� ������ �ؾ�����
	// �����ͷ� �ؾ�����.

	// ���� �����ϰų� �������� ���� ���ɼ��� �ִٸ� => ������
	// ����� ������� �ʾƾ� �ϸ� => ����
	// ������ �����Ҵ��� ����� �ʾұ� ������ 
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

