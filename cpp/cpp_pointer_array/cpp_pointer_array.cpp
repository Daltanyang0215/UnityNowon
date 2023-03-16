
#include <iostream>
using namespace std;

void DoChange(int tarray[][2], int trow, int tcol, int tvalue);
void DoChange1D(int tarray[], int index, int tvalue);
void DoChange1Dptr(int* tarray, int index, int tvalue);

int main()
{
	int tA = 7;

	int* tpA = nullptr;

	tpA = &tA;

	*tpA = 777;

	cout << tA << endl;
	///////////////////////////////////////////////////////////////////////////////

	int tArray[5] = { 0,1,2,3,4 };

	tArray[0] = 7;
	cout << endl;
	for (auto t : tArray)
	{
		cout << t << endl;
	}

	cout << endl;
	// 배열의 이름(배열 시작의 포인트 값) 의 덧셈은 (포인트)주소값 만큼의 증가를 이야기한다
	*(tArray + 1) = 9;
	for (auto t : tArray)
	{
		cout << t << endl;
	}


	///////////////////////////////////////////////////////////////////////////////
	int tArray2D[3][2] =
	{
		{0,1},
		{1,2},
		{2,3}
	};

	//tArray2D[0][0] = 7;
	DoChange(tArray2D, 0, 0, 7);

	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++) {
			cout << tArray2D[i][j];
		}
		cout << endl;
	}


	int tArray1D[3] = { 1,2,3 };

	//tArray1D[0] = 7;
	DoChange1Dptr(tArray1D, 0, 7);
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << tArray1D[i];
		cout << endl;
	}

	return 0;
}
void DoChange(int tarray[][2], int trow, int tcol, int tvalue) {
	tarray[trow][tcol] = tvalue;
}

void DoChange1D(int tarray[], int index, int tvalue) {
	tarray[index] = tvalue;
}
void DoChange1Dptr(int* tarrayptr, int index, int tvalue) {
	tarrayptr[index] = tvalue;
}
