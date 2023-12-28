// class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class a {
public:
    a() {
        printf("%d", 10);

    }
};

class b {
public:
    b() {
        printf("%d", 20);

    }
};

class c {
public:
    c() {
        printf("%d", 30);

    }
};
class player : public a, public b, public c {
public:
    player()
        :a()
        ,b()
        ,c()
    {
        a = 10;
        b = 20;
        printf("%d", a);
        printf("%d", a);
    }

    player(int _a, int _b) {
        a = _a;
        b = _b;
    }
    int a;
    int b;
    void test() {
        printf("%d", a);
    }
};



int main()
{
    player* a;
    player b;
}

