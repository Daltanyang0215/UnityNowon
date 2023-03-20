#include "CUnit.h"

void CUnit::DoDamage(CUnit* tAttacker) {
    this->mHP -= tAttacker->GetAP();
}