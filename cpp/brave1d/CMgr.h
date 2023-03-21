#pragma once
// ����� �÷��� �����͸� �����ϴ� �Ŵ��� ����

/*
	�̱���. 3���� ������ �����Ͽ� �����
	1. static�� ������ �ش� Ŭ���� Ÿ���� ������ ����. instance�� �����Ѵ�
	2. �����ڴ� public�� �ƴϴ�.
	3. GetInstance() �Լ��� ���ǿ��� ��ü�� �ִ������ 1���� �����ϴ� �Ǵ�������� ��ġ�Ѵ�
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

