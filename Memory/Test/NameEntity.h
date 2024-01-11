#pragma once

class NameEntity
{
public:
	NameEntity();
	NameEntity(__int64 _Damage);
	virtual void update();
	virtual void DamageRender();
	__int64 GetDamage();
private:
	int Hp;
	__int64 Damage;
};

