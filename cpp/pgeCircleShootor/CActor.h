#pragma once
class CActor
{
public:
	float mActorX = .0f;
	float mActorY = .0f;
	float mActorMoveSpeed = 30.0f;

public:
	void DoMove(int x,int y, float t);
};

