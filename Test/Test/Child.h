#pragma once
#include "Parent.h"
class Child : public Parent
{
public:

	int att = 20;
	int getatt() override{
		return att;
	}
};

