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

	inline int GetHp() const {
		return Hp;
	}

	inline int GetGold() const{
		return Gold;
	}

	inline void SetGold(int _Gold) {
		Gold = _Gold;
	}

	inline void Heal() {
		Hp = GetMaxHp();
		SetGold(GetGold() - 3);
	}

	void StatusRender();
	inline int GetMaxHp() const {
		return MaxHp;
	}

	inline int GetMinAtt() const {
		return MinAtt + Weapon.GetAtt();
	}
	inline int GetMaxAtt() const {
		return MaxAtt + Weapon.GetAtt();
	}


protected:
	int GetRandomAtt() override;
	int MaxHp = Hp;
	int Gold = 10;
};

