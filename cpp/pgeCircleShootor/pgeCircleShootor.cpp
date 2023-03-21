#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class pgeCircleShootor : public olc::PixelGameEngine
{
public:
	pgeCircleShootor()
	{
		// Name your application
		sAppName = "pgeCircleShootor";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		this->Clear(olc::BLACK);
		DrawLineEquaion(0, 0, 100, 100);

		return true;
	}

	void DrawLineEquaion(int tX_0, int tY_0, int tX_1, int tY_1);
};

int main()
{
	pgeCircleShootor tShootor;
	if (tShootor.Construct(320, 240, 2, 2))
		tShootor.Start();
	return 0;
}

void pgeCircleShootor::DrawLineEquaion(int tX_0, int tY_0, int tX_1, int tY_1) {
	float tSlopeRatio = 0;

	tSlopeRatio = (float)(tY_1 - tY_0) / (tX_1 - tX_0);

	int tX = 0;
	int tY = 0;

	for (tX = tX_0 ; tX <= tX_1 ; ++tX)
	{
		tY = tSlopeRatio*(tX - tX_0) + tY_0;

		Draw(tX, tY);
	}
}