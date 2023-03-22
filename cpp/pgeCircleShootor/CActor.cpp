#include "CActor.h"
void CActor::DoMove(int x, int y, float t) {
	mActorX += x * mActorMoveSpeed * t;
	mActorY -= y * mActorMoveSpeed * t;
}