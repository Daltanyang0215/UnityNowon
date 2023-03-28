#pragma once
#include "olcPixelGameEngine.h"
#include "CActor.h"
#include "CBullet.h"

#include <vector>
using namespace std;

enum scenetype{
	SCENE_TITLE=0,
	SCENE_PLAYGAME
};

class CEnemy;
// Override base class with your custom functionality
class pgeCircleShootor : public olc::PixelGameEngine
{
	CActor* mActor = nullptr;
	CEnemy* mEnemy = nullptr;
	CEnemy* mEnemyAimed = nullptr;
	CEnemy* mEnemyCircle = nullptr;
	vector<CBullet*> mBullets;
	vector<CBullet*> mBulletsEnemy;
	vector<CBullet*> mBulletsEnemyAimed;
	vector<CBullet*> mBulletsEnemyCircled;

	scenetype mCurScenType = SCENE_TITLE;

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

	void UpdateTitle();

	void UpdatePlayGame(float fElapsedTime);
	

	void DrawLineEquation(int tX_0, int tY_0, int tX_1, int tY_1);
	void DrawCircleEquation(int tXCenter, int tYCenter, int tRadius, olc::Pixel tColor);
};
