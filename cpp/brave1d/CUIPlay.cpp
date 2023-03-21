#include "CUIPlay.h"
#include "CMgr.h"
#include<iostream>

using namespace std;

void CUIPlay::Display() 
{
	cout << "Brave's EXP : " << CMgr::GetInstance()->mExp << endl;
}