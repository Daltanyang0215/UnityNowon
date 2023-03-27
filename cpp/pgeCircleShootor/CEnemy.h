#pragma once
#include "CUnit.h"

#include <vector>
using namespace std;

class CBullet;

class CEnemy :    public CUnit
{
public:
	float mTimeTick;

public:
	virtual void DoMove(olc::vf2d tVelocity, float t) override;
	void DoFire(vector<CBullet*>& tBullets);
	void DoFireAimed(vector<CBullet*>& tBullets,CUnit* tpTarget);

private:
	int mCurIndexBullet;
};

