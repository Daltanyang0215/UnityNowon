#include "CBrave.h"
#include "CSlime.h"

// :: 영역결정연산자 (c# . )
 CBrave::CBrave() {
	 mX = 0;
	 mHP = 1000;
	 mAP = 100;
}

void CBrave::DoMove(int tVelocity) {
	this->mX += tVelocity;


}
void CBrave::DoDamage(CUnit* tAttacker) {

	this->mHP -= tAttacker->GetAP();
}