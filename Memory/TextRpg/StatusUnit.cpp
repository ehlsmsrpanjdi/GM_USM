#include "StatusUnit.h"
#include <iostream>
#include "MyMath.h"

void StatusUnit::SetName(const char* _Name)
{
	int Index = 0;
	while (_Name[Index]) {
		Name[Index] = _Name[Index];
		++Index;
	}
}

void StatusUnit::StatusRender()
{
	// 메모리에 관련된 명확한 설명은 안한 상태지만
	// 자신의 맴버함수에서 자신의 맴버변수는 자유롭게 사용이 가능합니다.
	int Size = printf_s("%s ", Name);
	for (int i = 0; i < 50 - Size; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
	printf_s("공격력 %d~%d\n", GetMinAtt(), GetMaxAtt());
	printf_s("체력 %d\n", Hp);

	for (int i = 0; i < 50; i++)
	{
		printf_s("-");
	}

	printf_s("\n");
}

int StatusUnit::GetDamage()
{
	SetPresentDamage((rand() % MinAtt + 1) + (MaxAtt - MinAtt));
	return GetpresentDamage();
}

int StatusUnit::GetSpeed()
{
	return rand() % Speed;
}
