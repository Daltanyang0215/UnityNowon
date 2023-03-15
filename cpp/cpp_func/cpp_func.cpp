
#include <iostream>

using namespace std;

int DoAddictive(int, int);
int DoSub(int, int);
int DoMut(int, int);
float DoDiv(float, float);


int main()
{

	int tA = 3;
	int tB = 2;

	int tResult;

	tResult = DoAddictive(tA, tB);
	cout << "+의 결과 값 :" << tResult << endl;

	tResult = DoSub(tA, tB);
	cout << "-의 결과 값 :" << tResult << endl;

	tResult = DoMut(tA, tB);
	cout << "*의 결과 값 :" << tResult << endl;

	float tResultF = DoDiv((float)tA, (float)tB);
	cout << "*의 결과 값 :" << tResultF << endl;

}


int DoAddictive(int a, int b) {
	return a + b;
}
int DoSub(int a, int b) {
	return a + b;
}
int DoMut(int a, int b) {
	return a * b;
}
float DoDiv(float a, float b) {
	return a / b;
}
