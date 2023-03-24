#include "CBrave.h"
#include "CSlime.h"
#include<iostream>
using namespace std;
// :: �������������� (c# . )
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

	cout << "��簡 ���ݹ޾Ҵ�" << endl;
	this->DisplayHP();
	tAttacker->DisplayHP();
}

void CBrave::Heal() {
	this->mHP = this->mHPMAX;
	cout << "��簡 ü���� ȸ���Ͽ���" << endl;
	this->DisplayHP();
}

void CBrave::DisplayHP() {
	cout << "��� HP : \t"<<this->mHP<<"\t/"<<this->mHPMAX << endl;
}