// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
template <typename T>
class test {
public:

	T GetValue() {
		return Value;
	}

	void SetValue(T _Value) {
		Value = _Value;
	}

	T Value;

};


class test1 {
public:

	int Value;

	int GetIndex() {
		return Value;
	}
};

class test2 {
public:

	test1* Value;


};

int main() {
	test<int>* A1 = new test<int>[10];


	test<int>* A2 = new test<int>[10];



	for (int i = 0; i < 10; i++)
	{
		A1[i].SetValue(i);
		A2[i].SetValue(i);
	}



	test<test<int>*>* B = new test<test<int>*>[2];
	B[0].SetValue(A1);
	B[1].SetValue(A2);

	int* A3 = new int[10];
	int** B1 = new int* [2];
	B1[0] = A3;
	B1[0][3] = 10;

	//이거 위와 아래 둘다 똑같은 거다.


	for (int i = 0;  i < 2; i++)
	{
		for (int j = 0;  j < 10;  j++)
		{
			B[i].GetValue()[j].SetValue(0);
			// B[i] => <test<int>*> B  
			// B[i].GetValue() => *A
			// 그런데 B[i][j]가 안되는 이유는 둘이 타입이 달라서 그렇다.
			// 메소드 오버로딩해주면 문제없이 될 것이다.
			// B[i].GetValue()[j] => A
			// B[i].GetValue()[j].SetValue(0) => A.Value = 0

		}
	}


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << B[i].GetValue()[j].GetValue() << "기입 후" << std::endl;
			// B => <test<int>*> *B
			// B[i] => test<int>* B => *A  
			// 그런데 B[i][j]가 안되는 이유는 둘이 타입이 달라서 그렇다.
			// 메소드 오버로딩해주면 문제없이 될 것이다.
			// B[i].GetValue() => *A
			// B[i].GetValue().[j] = A
			// B[i].GetValue()[j].GetValue() = A.Value()

		}
	}
}

