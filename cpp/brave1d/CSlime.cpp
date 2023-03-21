#include "CSlime.h"
#include "CBrave.h"

#include "CMgr.h"
#include<iostream>
using namespace std;

CSlime::CSlime() {
    mAP = 500;
    mHP = 200;
    mHPMAX = 200;
}

void CSlime:: DoDamage(CUnit* tAttacker) {
    this->mHP -= tAttacker->GetAP();

    CMgr::GetInstance()->mExp += 100;
    cout << "슬라임이 공격 받았다" << endl;
    tAttacker->DisplayHP();
    this->DisplayHP();
}

void CSlime::DisplayHP() {
    cout << "슬라임 HP : \t" << this->mHP << "\t/" << this->mHPMAX << endl;
}