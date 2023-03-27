#include "CEnemy.h"


#include "CBullet.h"
#include "config.h"

void CEnemy::DoMove(olc::vf2d tVelocity, float t) {
	CUnit::DoMove(tVelocity, t); // c#-> base();

	if (mPosition.x < 0 + this->mRadius) {
		mActorMoveSpeed = 40;
	}
	if (mPosition.x > 320 - this->mRadius - 1) {
		mActorMoveSpeed = -40;
	}
	if (mPosition.y < 0 + this->mRadius) {
		mPosition.y = this->mRadius;
	}
	if (mPosition.y > 240 - this->mRadius - 1) {
		mPosition.y = 240 - this->mRadius - 1;
	}
}

void CEnemy::DoFire(vector<CBullet*>& tBullets) {
	tBullets[mCurIndexBullet]->mPosition = this->mPosition;
	tBullets[mCurIndexBullet]->mIsActive = true;
	tBullets[mCurIndexBullet]->mMoveVector = olc::vf2d(0, 1);
	if (mCurIndexBullet < ENEMY_BULLET_COUNT - 1) {
		mCurIndexBullet++;
	}
	else {
		mCurIndexBullet = 0;
	}
}
void CEnemy::DoFireAimed(vector<CBullet*>& tBullets, CUnit* tpTarget) {
	tBullets[mCurIndexBullet]->mPosition = this->mPosition;
	tBullets[mCurIndexBullet]->mIsActive = true;
	tBullets[mCurIndexBullet]->mMoveVector = tpTarget->mPosition - mPosition;

	if (mCurIndexBullet < ENEMY_BULLET_COUNT - 1) {
		mCurIndexBullet++;
	}
	else {
		mCurIndexBullet = 0;
	}
}