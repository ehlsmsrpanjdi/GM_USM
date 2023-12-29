#include "Player.h"
#include <iostream>

Player::Player()
{
	// ���� �׽�Ʈ �ڵ�
	Weapon.SetName("Steel Sword");
	Weapon.SetAtt(10);
}

int Player::GetRandomAtt()
{
	CurDamage = FightUnit::GetRandomAtt() + Weapon.GetAtt();
	return CurDamage;
}

void Player::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("���ݷ� %d~%d\n", GetMinAtt(), GetMaxAtt());
	printf_s("ü�� %d\n", GetHp());

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}