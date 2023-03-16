
#include <iostream>
using namespace std;

class CUnit
{
private:
	int mX = 0;

public:
	CUnit();
	~CUnit();

public:
	void DisplayInfo();
};

CUnit::CUnit()
{
	cout << "생성" << endl;
}

CUnit::~CUnit()
{
	cout << "소멸" << endl;
}
void CUnit::DisplayInfo() {
	cout << mX << endl;
}

int main()
{
	int* tPtr = new int();

	if (tPtr != nullptr) {
		delete tPtr;
		tPtr = nullptr;
	}

	CUnit* tunit = new CUnit;
	
	tunit->DisplayInfo();

	if (tunit != nullptr) {
		delete tunit;
		tunit = nullptr;
	}
	return 0;
}
