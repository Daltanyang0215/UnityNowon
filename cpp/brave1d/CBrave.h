#pragma once

#include "CUnit.h"
//#include "Clime.h"

// 클래스 전방 선언. 클래스의 이름만 미리 알려준다
class CSlime;

class CBrave : public CUnit
{
private:
    int mX = 0;

public:
    CBrave();
    virtual ~CBrave() {};
    void DoMove(int tVelocity);
    void Heal();

    //void DoDamage(CSlime* tSlime);
    virtual void DoDamage(CUnit* tAttacker) override ;
    inline const int GetX() const { return mX; }
    virtual void DisplayHP() override;
};

