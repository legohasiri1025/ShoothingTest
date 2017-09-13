#include "front.h"
#include"DxLib.h"
#include "player.h"

front::front() {
	front_g = LoadGraph("../front/front_front.png");
	score_front = 100000;
	bomb_front = bomb;
	player_front = player_num;
	front_power = power;
	front_point = point;
	front_graze = graze;
}

void front::draw() {
	DrawGraph(0, 0, front_g, TRUE);
}