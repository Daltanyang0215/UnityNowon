#include "CUnit.h"
#include "pgeCircleShootor.h"
void CUnit::DoMove(int x, int y, float t) {
	mPosition.x += x * mActorMoveSpeed * t;
	mPosition.y -= y * mActorMoveSpeed * t;
}

void CUnit::DoMove(olc::vf2d tVelocity, float t) {
	if (mIsActive == false) return;
	mPosition += (tVelocity.mag2() > 0 ? tVelocity.norm() : tVelocity) * mActorMoveSpeed * t;
}

void CUnit::Render(olc::PixelGameEngine* tpEngine)
{
	if (mIsActive == false) return;
	((pgeCircleShootor*)tpEngine)->DrawCircleEquation(this->mPosition.x, this->mPosition.y, mRadius,color);
}