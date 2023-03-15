
#include <iostream>
using namespace std;

int main()
{
    int tA = 7;

    int* tpA = nullptr;

    tpA = &tA;

    *tpA = 777;

    cout << tA << endl;
    ///////////////////////////////////////////////////////////////////////////////

    int tArray[5] = {0,1,2,3,4};

    tArray[0] = 7;
    cout <<  endl;
    for (auto t:tArray)
    {
        cout << t << endl;
    }

    cout <<  endl;
    // 배열의 이름(배열 시작의 포인트 값) 의 덧셈은 (포인트)주소값 만큼의 증가를 이야기한다
    *(tArray + 1) = 9;
    for (auto t : tArray)
    {
        cout << t << endl;
    }

    return 0;
}