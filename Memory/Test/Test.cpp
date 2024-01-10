// Node.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 자료구조의 메모리의 2가지 형태중 하나로서
// 어떠한 데이터가 자기자신의 데이터의 참조형을 n개 가지면 
// 그걸 노드구조라고 한다.

typedef int DataType;

class Node
{
public:
    DataType Value;
    Node* Next = nullptr;
};

int main()
{
    Node Node0;
    Node Node1;
    Node Node2;
    Node Node3;
    Node Node4;
    Node Node5;
    Node Node6;

    Node0.Value = 0;
    Node1.Value = 1;
    Node2.Value = 2;
    Node3.Value = 3;
    Node4.Value = 4;
    Node5.Value = 5;
    Node6.Value = 6;

    Node0.Next = &Node1;
    Node1.Next = &Node2;
    Node2.Next = &Node3;
    Node3.Next = &Node4;
    Node4.Next = &Node5;
    Node5.Next = &Node6;














    Node* CurNode = &Node0;

    while (true) {
        std::cout << CurNode->Value << std::endl;
        if (nullptr == CurNode->Next) {
            break;
        }
        CurNode = CurNode->Next;
    }
    // CurNode 만 가지고
    // 나머지 모든 값을 출력하세요.
}
