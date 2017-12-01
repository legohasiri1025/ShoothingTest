#ifndef _PLAYER_
#define _PLAYER_
#include "define.h"

class player {
protected:
	unsigned char playermode;
	unsigned char player_num;
	unsigned char bomb;
	unsigned char option;
	unsigned char graze;
	double power;
	unsigned int point;
	Graph_ graphic[24];
	Graph_ slow_effe;
	Point_ px;
	Point_ py;
	Count_ count1;
	Count_ count2;
	int speed;

	bool life;
	bool right;
	bool left;
	bool down;
	bool up;
	bool slow;
	int i;
	int j;

	//shot
	Point_ sx[P_MAX_SHOT][2];
	Point_ sy[P_MAX_SHOT][2];
	int shotspeed;
	int subspeed;
	int span;
	Count_ shotcount1;
	Count_ shotcount2;
	double m_power;
	double s_power;
	Graph_ mainshotgr;
	Graph_ optionshotgr;
	Graph_ optiongr;
	Sound_ shotse;
	bool p_shot[P_MAX_SHOT][2];
	bool hit[P_MAX_SHOT][2];
	bool shotkey;
public:
	player();
	void move();
	void draw();
	//shot
	void mainshot1();
	void mainshot2();
	bool shot_key();
	void optionshot();

	void updata();

	int GetPlayerX();
	int GetPlayerY();
	void SetPlayerX(Point_ x);
	void SetPlayerY(Point_ y);
};
/*
class shot : protected player {
private:
	Point_ sx[P_MAX_SHOT][2];
	Point_ sy[P_MAX_SHOT][2];
	int shotspeed;
	int subspeed;
	int span;
	Count_ shotcount1;
	Count_ shotcount2;
	double m_power;
	double s_power;
	Graph_ mainshotgr;
	Graph_ optionshotgr;
	Graph_ optiongr;
	Sound_ shotse;
	bool p_shot[P_MAX_SHOT][2];
	bool hit[P_MAX_SHOT][2];
public:
	shot();
	void mainshot1();
	void mainshot2();
	void optionshot();
};*/

/*class bomb :public shot {
private:
	int time;
};*/

#endif