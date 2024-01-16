#include "StatusUnit.h"
#include <iostream>


void StatusUnit::StatusRenderStart()
{

}

void StatusUnit::StatusRenderBase()
{
	printf_s("���ݷ� %d~%d\n", MinAtt, MaxAtt);
	printf_s("ü�� %d/%d\n", Hp, MaxHp);
	printf_s("������ %d\n", Gold);
}
void StatusUnit::StatusRenderEnd()
{

}

void StatusUnit::StatusRender()
{
	// �޸𸮿� ���õ� ��Ȯ�� ������ ���� ��������
	// �ڽ��� �ɹ��Լ����� �ڽ��� �ɹ������� �����Ӱ� ����� �����մϴ�.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	StatusRenderStart();
	StatusRenderBase();
	StatusRenderEnd();

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

void StatusUnit::RandomGold(int _Min, int _Max)
{
	Gold = RandomValue(_Min, _Max) * (this->MinAtt / 5);
}

void StatusUnit::RandomExp(int _Min, int _Max)
{
	Exp = RandomValue(_Min, _Max) * (this->MinAtt / 5);
}

int StatusUnit::RandomValue(int _Min, int _Max)
{
	return (rand() % (_Max - _Min)) + _Min;
}