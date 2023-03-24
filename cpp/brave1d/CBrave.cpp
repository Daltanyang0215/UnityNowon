#include "CBrave.h"
#include "CSlime.h"
#include<iostream>
using namespace std;
// :: 영역결정연산자 (c# . )
 CBrave::CBrave() {
	 mX = 0;
	 mHP = 1000;
	 mHPMAX = 1000;
	 mAP = 100;
}

void CBrave::DoMove(int tVelocity) {
	this->mX += tVelocity;


}
void CBrave::DoDamage(CUnit* tAttacker) {

	this->mHP -= tAttacker->GetAP();

	cout << "용사가 공격받았다" << endl;
	this->DisplayHP();
	tAttacker->DisplayHP();
}

void CBrave::Heal() {
	this->mHP = this->mHPMAX;
	cout << "용사가 체력을 회복하였다" << endl;
	this->DisplayHP();
}

void CBrave::DisplayHP() {
	cout << "용사 HP : \t"<<this->mHP<<"\t/"<<this->mHPMAX << endl;
}