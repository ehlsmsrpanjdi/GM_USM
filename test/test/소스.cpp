#include <iostream>


class A {
	friend class B;
	int test = 3;
	int test() {
		return 1;
	}

	void test2() {
		test = 5;
	}
};
template<typename ObjectType>
class B {
public:
	int test3() {
		ObjectType* a = new ObjectType();
		a.test2();

	}
};


int main() {
	B<int> a;
	a.test3();
}