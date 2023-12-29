#pragma once
#include <iostream>
class Parent
{
public:
	Parent();

	int att = 10;

	virtual int getatt() {
		return att;
	}

};

