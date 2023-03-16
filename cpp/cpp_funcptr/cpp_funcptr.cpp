
#include <iostream>
using namespace std;

int DoAddictive(int tA, int tB);

int main()
{
    int tResult = 0;
    tResult = DoAddictive(3, 2);
    cout << tResult << endl;
    
    int (*funcPtr)(int, int) = nullptr;
    funcPtr = DoAddictive;

    tResult = funcPtr(3, 3);
    cout << tResult << endl;

    typedef int (*FuncPtr)(int, int);

    FuncPtr tpPtr = nullptr;

    tpPtr = DoAddictive;

    tResult = tpPtr(4, 8);
    cout << tResult << endl;


    return 0;
}

int DoAddictive(int tA, int tB) {
    return tA + tB;
}