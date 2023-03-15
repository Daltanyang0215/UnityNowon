#include <iostream>

using namespace std;

void Swap(int, int);

int main()
{

	int tA = 3;
	int tB = 2;

	cout << tA << endl;
	cout << tB << endl;

	Swap(tA, tB);

	cout <<  endl;
	cout << tA << endl;
	cout << tB << endl;


	return 0;
}

void Swap(int a, int b) {

	int tTemp = 0;
	tTemp = a;
	a = b;
	b = tTemp;
}