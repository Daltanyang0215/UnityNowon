
#include <iostream>
using namespace std;

int main()
{

	int tA = 3;
	int tB = 2;

	cout << "tA : " << tA << endl;
	cout << "tB : " << tB << endl;

	DoSwap(&tA, &tB);


	cout << endl;
	cout << "tA : " << tA << endl;
	cout << "tB : " << tB << endl;

	return 0;
}


void DoSwap(int* a, int* b) {
	int tTemp = 0;
	tTemp = *a;
	*a = *b;
	*b = tTemp;
}