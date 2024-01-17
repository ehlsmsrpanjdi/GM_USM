#include "Part.h"
#include "Body.h"

void Part::AddPart(Part* _Part)
{
	if (nullptr != GetBack()) {

		Part* TempBack = GetBack();
		while (nullptr != TempBack->GetBack()) {
			TempBack = TempBack->GetBack();
		}
		TempBack->SetBack(_Part);
		_Part->SetFront(TempBack);
	}
	else {
		SetBack(_Part);
		_Part->SetFront(this);
	}
}

void Part::Move()
{
	{
			if (nullptr != GetBack()) {
				Part* TempBack = GetBack();
				while (nullptr != TempBack) {
					TempBack->SetPrevLocation(TempBack->GetPos());
					int2 TempPos = TempBack->Front->PrevLocation;
					TempBack->SetPos(TempPos);
					TempBack = TempBack->GetBack();
				}
			}
	}
}
