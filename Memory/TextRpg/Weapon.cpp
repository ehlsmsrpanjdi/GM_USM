#include "Weapon.h"
#include <random>

int Weapon::Upgrade() const {
	int Ramdom = rand() % 2;
	if (Ramdom) {
		printf_s("��ȭ ����\n");
	}
	else {
		printf_s("��ȭ ����\n");
	}
	return Ramdom;
}


void Weapon::UpgradeResult()
{
	if (GetEquipUp() <= 10) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("���� ��ȭ��ġ = %d\n", GetEquipUp());
		}
	}
	else if (GetEquipUp() <= 20) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("���� ��ȭ��ġ = %d\n", GetEquipUp());
		}
		else {
			SetEquipUp(GetEquipUp() - 5);
			printf_s("���� ��ȭ��ġ = %d\n", GetEquipUp());
		}
	}
	else if (GetEquipUp() <= 30) {
		if (Upgrade()) {
			SetEquipUp(GetEquipUp() + 1);
			printf_s("���� ��ȭ��ġ = %d\n", GetEquipUp());
		}
		else {
			SetEquipUp(0);
		}
	}
	else {
		printf_s("�ְ� �ܰ��� ��ȭ�Դϴ�.");
	}
}

// 2.��
// 1������ 10�������� �����ص� ��ȭ��ġ�� �������� �ʽ��ϴ�.
// 10������ 20�������� �����ϸ� ��ȭ��ġ�� 5�� �������ϴ�.
// 20������ 30�������� �����ϸ� ��ȭ��ġ�� 0�� �˴ϴ�.
// ��ȭȮ���� �������
