#define OLC_PGE_APPLICATION
#include "pgeCircleShootor.h"
#include "CActor.h"


int main()
{
	pgeCircleShootor tShootor;
	if (tShootor.Construct(320, 240, 2, 2))
		tShootor.Start();
	return 0;
}

bool pgeCircleShootor::OnUserCreate()
{
	mActor = new CActor();
	mActor->color = olc::BLUE;
	mActor->mPosition.x = ScreenWidth() * 0.5f;
	mActor->mPosition.y = ScreenHeight() * 0.5f + 75.0f;
	mActor->mIsActive = true;

	mBullets.clear();
	CBullet* tpBullet = nullptr;
	for (int i = 0; i < 10; i++)
	{
		tpBullet = new CBullet;
		// 지울거임
			tpBullet->mPosition.x = i*20;
		//
		tpBullet->mRadius = 3;
		tpBullet->color = olc::RED;
		mBullets.push_back(tpBullet);
	}

	return true;
}
bool pgeCircleShootor::OnUserDestroy() {
	if (mActor != nullptr) {
		delete mActor;
		mActor = nullptr;
	}
	//for (int i = 0; i < 10; i++)
	/*{
		delete mBullets[i];
		mBullets[i] = nullptr;
	}*/
	for (vector<CBullet*>::iterator t = mBullets.begin();t!=mBullets.end();++t)
	{
		if (*t != nullptr) {
			delete *t;
			*t = nullptr;
		}
	}
	mBullets.clear();
	return true;
}

bool pgeCircleShootor::OnUserUpdate(float fElapsedTime)
{
	this->Clear(olc::BLACK);
	//
	// 윈도우 좌표계라서 y축이 반전되어있음
	//

#pragma region player Movement
	olc::vf2d tVelocity(0, 0);
	if (GetKey(olc::UP).bHeld) {
		//mActor.mActorY -= mActor.mActorMoveSpeed * fElapsedTime;
		//mActor.DoMove(0, 1, fElapsedTime);
		tVelocity.y -= 1;
	}
	if (GetKey(olc::DOWN).bHeld) {
		//mActor.mActorY += mActor.mActorMoveSpeed * fElapsedTime;
		//mActor.DoMove(0, -1, fElapsedTime);
		tVelocity.y += 1;
	}
	if (GetKey(olc::RIGHT).bHeld) {
		//mActor.mActorX += mActor.mActorMoveSpeed * fElapsedTime;
		//mActor.DoMove(1, 0, fElapsedTime);
		tVelocity.x += 1;
	}
	if (GetKey(olc::LEFT).bHeld) {
		//mActor.mActorX -= mActor.mActorMoveSpeed * fElapsedTime;
		//mActor.DoMove(-1, 0, fElapsedTime);
		tVelocity.x -= 1;
	}
	mActor->DoMove(tVelocity, fElapsedTime);
#pragma endregion


	mActor->Render(this);

	for (vector<CBullet*>::iterator t = mBullets.begin(); t != mBullets.end(); ++t)
	{
		(*t)->Render(this);
	}

	return true;
}

void pgeCircleShootor::DrawLineEquation(int tX_0, int tY_0, int tX_1, int tY_1) {

	if (tX_0 == tX_1) {
		if (tY_0 > tY_1) {
			std::swap(tY_0, tY_1);
		}
		for (int tY = tY_0; tY <= tY_1; ++tY)
		{
			Draw(tX_0, tY);
		}
		return;
	}


	float tSlopeRatio = 0;

	tSlopeRatio = (float)(tY_1 - tY_0) / (tX_1 - tX_0);

	int tX = 0;
	int tY = 0;


	if ((tSlopeRatio > 0 ? tSlopeRatio : -tSlopeRatio) < 1)
	{
		if (tX_0 > tX_1) {
			std::swap(tX_0, tX_1);
			std::swap(tY_0, tY_1);
		}


		for (tX = tX_0; tX <= tX_1; ++tX)
		{
			tY = tSlopeRatio * (tX - tX_0) + tY_0 + 0.5f;

			Draw(tX, tY);
		}
	}
	else {
		if (tY_0 > tY_1) {
			std::swap(tX_0, tX_1);
			std::swap(tY_0, tY_1);
		}

		for (tY = tY_0; tY <= tY_1; ++tY)
		{
			tX = (tY - tY_0) / tSlopeRatio + tX_0 + 0.5f;

			Draw(tX, tY);
		}

	}
}

void pgeCircleShootor::DrawCircleEquation(int tXCenter, int tYCenter, int tRadius, olc::Pixel tColor = olc::WHITE)
{
	int tX = 0;
	int tY = 0;

	tX = 0;
	tY = tRadius;

	while (tY >= tX) {
		Draw(tX + tXCenter, tY + tYCenter, tColor);
		Draw(tY + tXCenter, tX + tYCenter, tColor);

		Draw(tX + tXCenter, -tY + tYCenter, tColor);
		Draw(tY + tXCenter, -tX + tYCenter, tColor);

		Draw(-tX + tXCenter, tY + tYCenter, tColor);
		Draw(-tY + tXCenter, tX + tYCenter, tColor);

		Draw(-tX + tXCenter, -tY + tYCenter, tColor);
		Draw(-tY + tXCenter, -tX + tYCenter, tColor);


		tX++;
		tY = std::sqrtf((float)tRadius * tRadius - tX * tX) + 0.5f;
	}

}