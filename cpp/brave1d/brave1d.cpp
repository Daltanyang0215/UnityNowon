//
//  main.cpp
//  4_tiny_brave1d
//
//  Created by ryu on 2020/02/14.
//  Copyright © 2020 ryu. All rights reserved.
//


/*
 created by pokpoongryu


 지형속성:
 100    집
 200    세상의 끝
 1      슬라임 출몰 지역

 */

 /*
	  opp

	 추상화 -> 데이터 + 코드의 추상화 -> 테이터의 추상화
		 멤버변수와 함수를 클래스별로 나눔

	 은닉화
		 멤버함수 뒤로 멘버변수를 감춘다. (모든 프로퍼티는 비공개로 하며 프로퍼티에 접근은 함수로만 되도록 설계한것)

	 상속성
		 공통된 속성들을 부모클래스에 두고, 자식클래스 들은 부모클래스를 이어받아 작성한다.

	 다향성
		 동일한 메시지(함수)에 다른 반응. 상위클래스의 함수를 호출하여 자식의 기능을 사용


	디자인 패턴

	싱글톤 패턴 - 생성(객체를 어떻게 생성할 것인지에 대한 해결책)
		목적 : 객체의 최대 생성갯수를 1개로 제한하는 패턴
 */

#include <iostream>
#include <time.h>

#include "CBrave.h"
#include "CSlime.h"
#include "CMgr.h"
#include "CUIPlay.h"

using namespace std;

//void DoMove(CBrave* tBrave, int tVelocity);

//void DoDamage(CBrave* tBrave, CSlime* tSlime);
//void DoDamage(CSlime* tSlime,CBrave* tBrave);

int main()
{
	srand((unsigned int)time(nullptr));

	int tWorld[9] = { 100, 0, 1,0,10,0,1, 0, 200 };

	CMgr::GetInstance();


	CBrave* tBrave = new CBrave;
	CSlime* tSlime = new CSlime;

	CUIPlay tUIPlay;

	char tMoveDir = 'd';

	cout << "((용사와 슬라임))" << endl;
	cout << "==종료하려면 n을 입력하세요==" << endl;


	while (true)
	{
		//input
		cout << "move?(a/d)";
		cin >> tMoveDir;


		if ('n' == tMoveDir)
		{
			cout << "brave is sleeping." << endl;
			break;
		}

		if ('a' == tMoveDir)
		{
			if (tBrave->GetX() > 0)
			{
				//tBrave.mX = tBrave.mX - 1;
				tBrave->DoMove(-1);
				cout << "<--move left" << endl;
			}
			else
			{
				cout << "Brave can not move any more." << endl;
			}
		}

		if ('d' == tMoveDir)
		{
			if (tBrave->GetX() < 4)
			{
				//tBrave.mX = tBrave.mX + 1;
				tBrave->DoMove(1);

				cout << "-->move right" << endl;
			}
			else
			{
				cout << "Brave can not move any more." << endl;
			}
		}

		int tAttrib = 0;
		tAttrib = tWorld[tBrave->GetX()];
		switch (tAttrib)
		{
		case 0: //아무것도 없음
		{
			cout << "No one here." << "(You are on" << tBrave->GetX() << "Tile)" << endl;
		}
		break;
		case 1: //슬라임 있음
		{
			cout << "Slime is here." << "(You are on" << tBrave->GetX() << "Tile)" << endl;

			char tIsRollDice = 'r';
			while (1)
			{
				cout << "Roll a Dice of Fate!(r):";
				cin >> tIsRollDice;

				if ('r' == tIsRollDice)
				{
					//roll dice
					int tDiceNumber = rand() % 6 + 1;
					cout << tDiceNumber << endl;

					//switch (tDiceNumber)
					//{
					//case 1:
					//case 2:
					//case 3:
					//{
					//	tBrave->DoDamage(tSlime);
					//	//tBrave.mHP = tBrave.mHP - tSlime.mAP;
					//	cout << "Brave is damaged" << endl;
					//}
					//break;
					//case 4:
					//case 5:
					//case 6:
					//{
					//	//tSlime.mHP = tSlime.mHP - tBrave.mAP;
					//	tSlime->DoDamage(tBrave);
					//	cout << "Slime is damaged." << endl;
					//}
					//break;
					//}
					//if (tSlime->GetHP() <= 0)
					//{
					//	cout << "Slime is very tired." << endl;
					//	break;
					//}
					//if (tBrave->GetHP() <= 0)
					//{
					//	cout << "Brave is very tired." << endl;
					//	break;
					//}
					CUnit* tpUnit = nullptr;
					CUnit* tpAttacker = nullptr;

					switch (tDiceNumber)
					{
					case 1:
					case 2:
					case 3:
					{
						tpUnit = tBrave;
						tpAttacker = tSlime;
						cout << "Brave is damaged" << endl;
					}
					break;
					case 4:
					case 5:
					case 6:
					{
						tpUnit = tSlime;
						tpAttacker = tBrave;
						cout << "Slime is damaged." << endl;
					}
					break;
					}
					tpUnit->DoDamage(tpAttacker);


					if (tSlime->GetHP() <= 0)
					{
						cout << "Slime is very tired." << endl;
						CMgr::GetInstance()->mExp += 300;
						break;
					}
					if (tBrave->GetHP() <= 0)
					{
						cout << "Brave is very tired." << endl;

						break;
					}
				}
			}
			tUIPlay.Display();
		}
		break;
		case 10:
		{
			cout << "Brave is in clinic." << "(You are on" << tBrave->GetX() << "Tile)" << endl;
			tBrave->Heal();
		}
		case 100:
		{
			cout << "Brave is in home." << "(You are on" << tBrave->GetX() << "Tile)" << endl;
		}
		break;
		case 200:
		{
			cout << "Brave is in End of world." << "(You are on" << tBrave->GetX() << "Tile)" << endl;
		}
		break;
		}
	}


	tUIPlay.Display();

	if (tBrave != nullptr)
	{
		delete tBrave;
		tBrave = nullptr;
	}

	if (tSlime != nullptr)
	{
		delete tSlime;
		tSlime = nullptr;
	}

	return 0;
}

//void DoMove(CBrave* tBrave, int tVelocity) {
//    tBrave->mX = tBrave->mX + tVelocity;
//}

//void DoDamage(CBrave* tBrave, CSlime* tSlime) {
//    tBrave->mHP -= tSlime->mAP;
//}
//void DoDamage(CSlime* tSlime,CBrave* tBrave ) {
//    tSlime->mHP -= tBrave->mAP;
//}
