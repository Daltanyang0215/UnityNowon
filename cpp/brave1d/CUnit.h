#pragma once
class CUnit
{
public:
    CUnit() {};
    virtual ~CUnit() {};

protected :
    float mHP = 0.0f;
    float mHPMAX = 0.0f;
    float mAP = 0.0f;

public:
    inline const float GetHP() const { return mHP; }
    inline const float GetAP() const { return mAP; }
    virtual void DoDamage(CUnit* tAttacker);
    virtual void DisplayHP();
};

