#pragma once
class StatusUnit
{
public:
	void SetName(const char* _Name);
	void StatusRender();
	int GetDamage();
	int GetSpeed();

	inline int GetMinAtt() const
	{
		return MinAtt;
	}

	inline int GetMaxAtt() const {
		return MaxAtt;
	}

	inline void SetPresentDamage(int _PresentDamage) {
		PresentDamage = _PresentDamage;
	}

	inline int GetpresentDamage() const {
		return PresentDamage;
	}

protected:
	char Name[100] = "None";
	int Hp = 100;
	int MinAtt = 10;
	int MaxAtt = 20;
	int Speed = 20; // 0~20
	int Gold = 0;
	int PresentDamage = 0;

};

