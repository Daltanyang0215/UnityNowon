
#include <iostream>
using namespace std;

enum {
	STATE_IDLE = 0,
	STATE_ATTACK
};

void DoIdle() {

}
void DoAttack() {

}

int main()
{
	int tState = STATE_IDLE;

	if (tState == STATE_IDLE) {
		DoIdle();
	}
	if (tState == STATE_ATTACK) {
		DoAttack();
	}

	// 스위치문으로 제작시 상태가 증가함에따라 스위치문을 늘릴수가고 발생함. 속도방면에서는 동일함.
	// 배열로 접근시 선언부분에서만 늘리면 되며, 배열에 바로접근으로 속도방면에서는 동일함

	typedef void (*CFuncPtr)();

	CFuncPtr tArray[2] = { DoIdle,DoAttack };

	tArray[tState]();

	return 0;
}
