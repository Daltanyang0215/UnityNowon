
#include <iostream>

using namespace std;

unsigned int DoFactorial(unsigned int tN);

int main()
{
	int tResult = 0;

	tResult = DoFactorial(4);

	cout << tResult << endl;

	return 0;
}


unsigned int DoFactorial(unsigned int tN) {
	if (tN == 1) return 1;

	return tN * DoFactorial(tN - 1);
}