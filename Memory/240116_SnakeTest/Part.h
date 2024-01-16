#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	inline void SetPrevLocation(int2 _PrevLocation) {
		SetPrevLocation(_PrevLocation.X, _PrevLocation.Y);
	}
	inline void SetPrevLocation(int _X, int _Y) {
		PrevLocation.X = _X;
		PrevLocation.Y = _Y;
	}

	inline void SetPrevDirection(int2 _PrevDirection) {
		SetPrevDirection(_PrevDirection.X, _PrevDirection.Y);
	}

	inline void SetPrevDirection(int _X, int _Y) {
		PrevDirection.X = _X;
		PrevDirection.Y = _Y;
	}

	inline int2 GetPrevDirection() {
		return PrevDirection;
	}




	Part* GetBack() {
		return Back;
	}

	void SetBack(Part* _Back) {
		Back = _Back;
	}

	void SetFront(Part* _Front) {
		Front = _Front;
	}

	void AddPart(Part* _Part);
	
	void Move(bool _IsMove);

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
	int2 PrevLocation = { 0,0 };
	int2 PrevDirection = { 0,0 };
};

