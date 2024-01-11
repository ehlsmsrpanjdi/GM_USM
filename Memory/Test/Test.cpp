// Node.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "NameEntity.h"

// 자료구조의 메모리의 2가지 형태중 하나로서
// 어떠한 데이터가 자기자신의 데이터의 참조형을 n개 가지면 
// 그걸 노드구조라고 한다.

class A {
	int* a = new int();
	int* b = new int();
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);

	A *a = new A();

	delete a;
}

