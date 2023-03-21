#pragma once
// 용사의 플레이 데이터를 관리하는 매니저 역할

/*
	싱글톤. 3가지 구성을 결합하여 만든다
	1. static를 적용한 해당 클래스 타입의 포인터 변수. instance를 생성한다
	2. 생성자는 public이 아니다.
	3. GetInstance() 함수의 정의에는 객체의 최대생성을 1개로 제어하는 판단제어구조를 위치한다
*/
class CMgr
{
private:
	static CMgr* instance;

	CMgr();
	~CMgr();

public:
	int mExp=0;
	static CMgr* GetInstance();
};

