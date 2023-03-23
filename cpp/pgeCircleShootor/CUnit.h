#pragma once
#include "olcPixelGameEngine.h"
#include "pgeCircleShootor.h"
class CUnit
{
public:
	olc::vf2d mPosition;
	float mActorMoveSpeed = 30.0f;
	float mRadius = 15;
	olc::Pixel color = olc::WHITE;

public:
	void DoMove(int x,int y, float t);
	void DoMove(olc::vf2d tVelocity, float t);
	void Render();
};

