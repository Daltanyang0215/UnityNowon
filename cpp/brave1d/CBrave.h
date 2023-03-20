#pragma once

#include "CUnit.h"
//#include "Clime.h"

// Ŭ���� ���� ����. Ŭ������ �̸��� �̸� �˷��ش�
class CSlime;

class CBrave : public CUnit
{
private:
    int mX = 0;

public:
    CBrave();
    void DoMove(int tVelocity);
    //void DoDamage(CSlime* tSlime);
    virtual void DoDamage(CUnit* tAttacker) override ;
    inline const int GetX() const { return mX; }
};

