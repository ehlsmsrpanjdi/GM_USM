#include "Weapon.h"
#include <random>

int Weapon::Upgrade() const {
	int Ramdom = rand() % 2;
	if (Ramdom) {
		printf_s("강화 성공\n");
	}
	else {
		printf_s("강화 실패\n");
	}
	return Ramdom;
}


void Weapon::UpgradeResult()
{
	if (GetEquipUp() <= 10) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("현재 강화수치 = %d\n", GetEquipUp());
		}
	}
	else if (GetEquipUp() <= 20) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("현재 강화수치 = %d\n", GetEquipUp());
		}
		else {
			SetEquipUp(GetEquipUp() - 5);
			printf_s("현재 강화수치 = %d\n", GetEquipUp());
		}
	}
	else if (GetEquipUp() <= 30) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("현재 강화수치 = %d\n", GetEquipUp());
		}
		else {
			SetEquipUp(0);
		}
	}
	else {
		printf_s("최고 단계의 강화입니다.");
	}
}

// 2.번
// 1강부터 10강까지는 실패해도 강화수치가 떨어지지 않습니다.
// 10강부터 20강까지는 실패하면 강화수치가 5씩 떨어집니다.
// 20강부터 30강까지는 실패하면 강화수치가 0이 됩니다.
// 강화확률은 마음대로
