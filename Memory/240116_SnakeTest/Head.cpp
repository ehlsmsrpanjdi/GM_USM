#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	this->SetPrevLocation(GetPos());
	switch (Select)
	{

	case 'A':
	case 'a':
		PosChange(Left);
		break;
	case 'S':
	case 's':
		PosChange(Down);
		break;
	case 'W':
	case 'w':
		PosChange(Up);
		break;
	case 'D':
	case 'd':
		PosChange(Right);
		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();
	if (CurBody->GetPos() == GetPos())
	{
		AddPart(CurBody);
		BodyManager::ResetBody();
	}

}

void Head::PosChange(int _X, int _Y)
{
	int2 TempPos = { _X,  _Y };
	int2 ReverseTempPos = { -1 * _X, -1 * _Y };
	int2 CurPos = GetPos();
	if (GetPrevDirection() == ReverseTempPos) {
		return;
	}

	int2 NextPos = CurPos + TempPos;
	if (NextPos.X < 0 || NextPos.X >= GetCore()->Screen.GetScreenX()) {
		return;
	}
	if (NextPos.Y < 0 || NextPos.Y >= GetCore()->Screen.GetScreenY()) {
		return;
	}

	AddPos(TempPos);
	SetPrevDirection(TempPos);
	Move();
	IsHit();
}

void Head::IsHit()
{
	int2 CurPos = this->GetPos();
	Part* NextPart = this->GetBack();
	while (nullptr != NextPart) {
		if (NextPart->GetPos() == CurPos) {
			GetCore()->EngineEnd();
			return;
		}
		NextPart = NextPart->GetBack();
	}
	
	return;
}


