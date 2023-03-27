#pragma once
#include "CUnit.h"

#include <vector>
using namespace std;

class CBullet;

class CActor : public CUnit
{
public:
	virtual void DoMove(olc::vf2d tVelocity, float t) override;
	void DoFire(vector<CBullet*>& tBullets);

private:
	int mCurIndexBullet;
};

