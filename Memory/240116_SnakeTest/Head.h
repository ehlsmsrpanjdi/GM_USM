#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	void Update() override;
	void PosChange(int2 _Pos) {
		PosChange(_Pos.X, _Pos.Y);
	}
	void PosChange(int _X, int _Y);
	bool IsMove = false;
};

