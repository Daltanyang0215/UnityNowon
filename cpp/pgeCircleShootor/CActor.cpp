#include "CActor.h"
#include "CBullet.h"
#include "config.h"

void CActor::DoMove(olc::vf2d tVelocity, float t) {
	CUnit::DoMove(tVelocity, t); // c#-> base();

	if (mPosition.x < 0+this->mRadius) {
		mPosition.x = this->mRadius;
	}
	if (mPosition.x > 320 - this->mRadius-1) {
		mPosition.x = 320 - this->mRadius-1;
	}
	if (mPosition.y < 0 + this->mRadius) {
		mPosition.y = this->mRadius;
	}			  
	if (mPosition.y > 240 - this->mRadius-1) {
		mPosition.y = 240 - this->mRadius-1;
	}
}

void CActor::DoFire(vector<CBullet*>& tBullets) {
	tBullets[mCurIndexBullet]->mPosition = this->mPosition;
	tBullets[mCurIndexBullet]->mIsActive = true;

	if (mCurIndexBullet < ACTOR_BULLET_COUNT - 1) {
		mCurIndexBullet++;
	}
	else {
		mCurIndexBullet=0;
	}
}

