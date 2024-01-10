// Array.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main() {

	std::vector<int> arr = std::vector<int>();

	arr.push_back(31234);

	arr.emplace_back(310);

	for (int i = 0; i < arr.capacity(); i++)
	{
		std::cout << arr[i] << std::endl;
	}



}

