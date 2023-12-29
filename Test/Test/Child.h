#pragma once
#include "Parent.h"
class Child : public Parent
{
public:
	Child() {
		gold = 30;
	}



	void test() {
		Child::gold;
		Parent::gold;
	}
};

