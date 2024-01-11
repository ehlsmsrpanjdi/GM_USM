#include "NameEntity.h"
#include <iostream>

NameEntity::NameEntity()
	:Hp(0)
	,Damage(0)
{
}

NameEntity::NameEntity(__int64 _Damage)
{
	Damage = _Damage;
}

void NameEntity::update()
{

}

void NameEntity::DamageRender()
{
	__int64 Temp = GetDamage();
	int Count = 0;
	while (Temp / 1000) {
		Temp /= 1000;
		++Count;
	}
	std::cout << Temp;
	while (Count--)
	{
		std::cout << "K";
	}
	std::cout << std::endl;
}

__int64 NameEntity::GetDamage()
{

	return this->Damage;
}
