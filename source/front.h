#ifndef _FRONT_
#define _FRONT_
#include "player.h"
#include "define.h"

class front :public player {
private:
	int enemy_marker_x;
	int enemy_marker_y;
	double enemy_marker_bright;
	Graph_ front_g;
	Graph_ playernum_g;
	Graph_ bomb_g;
	Graph_ level_g;
	Graph_ number_g;
	Graph_ ch_highscore_g;
	Graph_ ch_score_g;
	Graph_ ch_player_g;
	Graph_ ch_bomb_g;
	Graph_ ch_power_g;
	Graph_ ch_point_g;
	Graph_ ch_graze_g;
	Graph_ enemymarker_g;
public:
	front();
	void draw();
	//void updata();
};
#endif