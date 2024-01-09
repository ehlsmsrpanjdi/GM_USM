

#include <iostream>
#include <ConsoleEngine/EngineDebug.h>
class IntArray
{
    // private: 디폴트 접근제한 지정자
public:
    // 디폴트 생성자
    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    // 디폴트 복사 생성자
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);

        //NumValue = _Other.NumValue;
        //ArrPtr = _Other.ArrPtr;
    }
    // 디폴트 소멸자
    ~IntArray()
    {
        Release();
    }
    // 디폴트 대입연산자
    void operator=(const IntArray& _Other)
    {
        // 쉘로우 카피라고 부릅니다.
        // 이걸 얕은 복사라고 합니다.
        // 깊은 복사가 더 좋은 복사
        // 멍청한 일이 발생하는 경우가 있는데.
        // 얕은 복사 => 나빠 <= 아니다.
        // 참조만 복사하는 복사를 얕은 복사라고 합니다.
        // ArrPtr = _Other.ArrPtr;
        Copy(_Other);
    }

    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    int Num()
    {
        return NumValue;
    }

    void Copy(const IntArray& _Other)
    {
        NumValue = _Other.NumValue;

        // 깊은 복사를 해줘야 합니다.
        ReSize(NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }

    void ReSize(int _Size)
    {
        if (0 >= _Size)
        {
            MsgBoxAssert("배열의 크기가 0일수 없습니다");
        }
        int TempSize = NumValue;
        NumValue = _Size;

        if (nullptr != ArrPtr)
        {
            TempPtr = ArrPtr;
            ArrPtr = new int[_Size];

            for (int i = 0; i < TempSize; i++)
            {
                ArrPtr[i] = TempPtr[i];
            }
            delete[] TempPtr;
            TempPtr = nullptr;
        }
        else {
            ArrPtr = new int[_Size];
        }


    }

    void Release()
    {
        if (nullptr != ArrPtr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }

private:
    int NumValue = 0;
    int* ArrPtr = nullptr;
    int* TempPtr = nullptr;
};


int main()
{
    IntArray NewArray = IntArray(5);
    // [?][?][?][?][?]

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }



    // 리사이즈 값은 얼마든지 변경될 수 있다.
    NewArray.ReSize(10);
    // ?는 무슨값이 들어가 있어도 괜찮다.
    // [0][1][2][3][4][?][?][?][?][?]

    for (size_t i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }

}
