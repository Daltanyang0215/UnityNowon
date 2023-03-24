#pragma once
#include "CUnit.h"

#include <vector>
using namespace std;

class CBullet;

class CActor : public CUnit
{
public:
	void DoFire(vector<CBullet*>& tBullets);
};

