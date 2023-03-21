#pragma once

#include "CUnit.h"
//#include "CBrave.h"
class CBrave;

class CSlime : public CUnit
{
public:
	CSlime();
	virtual ~CSlime() {};

	//void DoDamage(CBrave* tBrave);
	virtual void DoDamage(CUnit* tAttacker);
	virtual void DisplayHP() override;
};

