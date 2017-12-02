#include "front.h"
#include"DxLib.h"
#include "player.h"

front::front() {
	front_g = LoadGraph("front/front_front.png");
	playernum_g = LoadGraph("front/front_life.png");
	bomb_g = LoadGraph("front/front_star.png");
	ch_highscore_g = LoadGraph("front/front_hiscore.png");
	ch_score_g = LoadGraph("front/front_score.png");
	ch_player_g = LoadGraph("front/front_player.png");
	ch_bomb_g = LoadGraph("front/front_bomb.png");
	ch_power_g = LoadGraph("front/front_power.png");
	ch_point_g = LoadGraph("front/front_point.png");
	ch_graze_g = LoadGraph("front/front_graze.png");
	enemymarker_g = LoadGraph("front/front_enemymarker.png");

	score_front = 100000;
	highscore = 100000;
	bomb_front = bomb;
	player_front = player_num;
	front_power = power;
	front_point = point;
	front_graze = graze;


}

void front::draw() {
	DrawGraph(0, 0, front_g, TRUE);
	DrawGraph(440, 60, ch_highscore_g, TRUE);
	DrawGraph(440, 80, ch_score_g, TRUE);
	DrawGraph(440, 110, ch_player_g, TRUE);
	DrawGraph(440, 130, ch_bomb_g, TRUE);
	DrawGraph(440, 150, ch_power_g, TRUE);
	DrawGraph(440, 170, ch_point_g, TRUE);
	DrawGraph(440, 190, ch_graze_g, TRUE);

	//’l‚Ì•\Ž¦
	DrawFormatString(520, 60, RGB(255, 255, 255), "%08d", highscore);
	DrawFormatString(520, 80, RGB(255, 255, 255), "%08d", score_front);
	DrawFormatString(520, 110, RGB(255, 255, 255), "%d", player_front);
	DrawFormatString(520, 130, RGB(255, 255, 255), "%d", bomb_front);
	DrawFormatString(520, 150, RGB(255, 255, 255), "%1.2f / 4.00", front_power);
	DrawFormatString(520, 170, RGB(255, 255, 255), "%d", front_point);
	DrawFormatString(520, 190, RGB(255, 255, 255), "%d", front_graze);
}