#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	void SetPrevLocation(int2 _PrevLocation) {
		SetPrevLocation(_PrevLocation.X, _PrevLocation.Y);
	}
	void SetPrevLocation(int _X, int _Y) {
		PrevLocation.X = _X;
		PrevLocation.Y = _Y;
	}
	Part* GetBack() {
		return Back;
	}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
	int2 PrevLocation = { 0,0 };
};

