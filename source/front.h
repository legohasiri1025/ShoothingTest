#ifndef _FRONT_
#define _FRONT_
#include "player.h"
#include "define.h"

class front :public player {
private:
	unsigned int score_front;
	unsigned int highscore;
	unsigned char player_front;
	unsigned char bomb_front;
	double front_power;
	unsigned int front_point;
	unsigned char front_graze;
	int enemy_marker_x;
	int enemy_marker_y;
	double enemy_marker_bright;
	Graph_ front_g;
	Graph_ playernum_g;
	Graph_ bomb_g;
	Graph_ logo_g;
	Graph_ level_g;
	Graph_ number_g;
	Graph_ ch_highscore_g;
	Graph_ ch_score_g;
	Graph_ ch_power_g;
	Graph_ ch_point_g;
	Graph_ ch_graze_g;
	Graph_ enemy_marker_g;
public:
	front();
	void draw();
	void updata();
};
#endif