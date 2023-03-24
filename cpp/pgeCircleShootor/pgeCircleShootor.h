#pragma once
#include "olcPixelGameEngine.h"
#include "CActor.h"
#include "CBullet.h"

#include <vector>
using namespace std;
// Override base class with your custom functionality
class pgeCircleShootor : public olc::PixelGameEngine
{
	CActor* mActor = nullptr;
	vector<CBullet*> mBullets;

public:
	pgeCircleShootor()
	{
		// Name your application
		sAppName = "pgeCircleShootor";
	}

public:
	bool OnUserCreate() override;
	bool OnUserDestroy() override;
	bool OnUserUpdate(float fElapsedTime) override;
	

	void DrawLineEquation(int tX_0, int tY_0, int tX_1, int tY_1);
	void DrawCircleEquation(int tXCenter, int tYCenter, int tRadius, olc::Pixel tColor);
};
