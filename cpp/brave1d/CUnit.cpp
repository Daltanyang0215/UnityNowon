#include "CUnit.h"

#include <iostream>

using namespace std;

void CUnit::DoDamage(CUnit* tAttacker) {
    this->mHP -= tAttacker->GetAP();
}

void CUnit::DisplayHP() {

}