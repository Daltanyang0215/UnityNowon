#include "CSlime.h"
#include "CBrave.h"

CSlime::CSlime() {
    mAP = 500;
    mHP = 200;
}

void CSlime:: DoDamage(CUnit* tAttacker) {
    this->mHP -= tAttacker->GetAP();
}