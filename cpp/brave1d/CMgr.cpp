#include "CMgr.h"
CMgr* CMgr::instance = nullptr;

CMgr::CMgr()
{

};

CMgr::~CMgr()
{

};

CMgr* CMgr::GetInstance() {
	if (instance == nullptr) {
		instance = new CMgr();
	}
	return instance;
};