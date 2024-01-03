// Test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "ChildChild.h"

class A {
	int test() {
		int a;
		return 1;
	}

	int test1() {
		return 1;
	}

	int test2() {
		return 1;
	}
		

};

class B //: public A{
{
	void test() {

	}
};



int main()
{

	int* test = new int[100];

	delete test;

	int a = 30;

	test = &a;

	int b = 10;

}



