#include <iostream>
#include <map>
#include <ConsoleEngine/EngineDebug.h>
#include "Test.h"

typedef int KeyType;
typedef int DataType;


class MyPair {
public:
	MyPair() {

	}
	MyPair(KeyType _Key, DataType _Data)
		:Key(_Key)
		, Data(_Data)
	{
	}
	KeyType Key = KeyType();
	DataType Data = DataType();

};
class MyMap {
private:
	class MapNode {
	public:
		MapNode() {

		}
		MyPair Pair;
		MapNode* Parent = nullptr;
		MapNode* RightChild = nullptr;
		MapNode* LeftChild = nullptr;

		void insertNode(MapNode* _Node) {
			_Node->Parent = this;

			if (this->Pair.Key > _Node->Pair.Key) {
				if (this->LeftChild == nullptr) {
					this->LeftChild = _Node;
					return;
				}
				this->LeftChild->insertNode(_Node);
			}

			if (this->Pair.Key < _Node->Pair.Key) {
				if (this->RightChild == nullptr) {
					this->RightChild = _Node;
					return;
				}
				this->RightChild->insertNode(_Node);
			}
			return;
		}

		bool ContainerNode(KeyType _Key) {
			Root.key
		}
	};
public:
	MyMap() {

	}
	//삽입만 해줄 것인데, const가 안 붙을 이유가 없다.
	void insert(const MyPair& _MyPair) {
		MapNode* NewNode = new MapNode();
		NewNode->Pair = _MyPair;
		if (Root == nullptr) {
			Root = NewNode;
			return;
		}
		Root->insertNode(/*Root, */NewNode);
	}


private:
	MapNode* Root = nullptr;
};
int main()
{
	LeckCheck;

	{
		std::cout << "내 맵" << std::endl;
		//      Key   Value
		MyMap NewMap = MyMap();
		// 오름차순 작은수 => 큰수로 정렬이 됩니다.
		NewMap.insert(MyPair(10, 0));
		NewMap.insert(MyPair(5, 0));
		NewMap.insert(MyPair(15, 0));
		NewMap.insert(MyPair(12, 99));
		NewMap.insert(MyPair(3, 0));
		NewMap.insert(MyPair(7, 0));




	}
}
