#include "CUnit.h"
void CUnit::DoMove(int x, int y, float t) {
	mPosition.x += x * mActorMoveSpeed * t;
	mPosition.y -= y * mActorMoveSpeed * t;
}

void CUnit::DoMove(olc::vf2d tVelocity, float t) {

	mPosition += (tVelocity.mag2() > 0 ? tVelocity.norm() : tVelocity) * mActorMoveSpeed * t;
}

void CUnit::Render() {
	
}