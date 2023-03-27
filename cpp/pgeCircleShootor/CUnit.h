#pragma once
#include "olcPixelGameEngine.h"
class CUnit
{
public:
	olc::vf2d mPosition;
	olc::vf2d mMoveVector;
	float mActorMoveSpeed = 60.0f;
	float mRadius = 15;
	olc::Pixel color = olc::WHITE;
	bool mIsActive = false;

public:
	void DoMove(int x,int y, float t);
	virtual void DoMove(olc::vf2d tVelocity, float t);
	void Render(olc::PixelGameEngine* tpEngine);
};

