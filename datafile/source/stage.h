#pragma once
#include "define.h"

class stage {
private:
	int stagenum;
	Count_ stagecount;
	bool stageclear;
public:
	stage();
	void stageinit();
	void stageupdate();
	void stage1();
	void stage2();
	void stage3();
	void stage4();
	void stage5();
	void stage6();
	void stageex();
};