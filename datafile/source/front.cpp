#include "front.h"
#include"DxLib.h"
#include "player.h"
#include "font.h"

front::front() {
	front_g = LoadGraph("datafile/front/front_front.png");
	playernum_g = LoadGraph("datafile/front/front_life.png");
	bomb_g = LoadGraph("datafile/front/front_star.png");
	ch_highscore_g = LoadGraph("datafile/front/front_hiscore.png");
	ch_score_g = LoadGraph("datafile/front/front_score.png");
	ch_player_g = LoadGraph("datafile/front/front_player.png");
	ch_bomb_g = LoadGraph("datafile/front/front_bomb.png");
	ch_power_g = LoadGraph("datafile/front/front_power.png");
	ch_point_g = LoadGraph("datafile/front/front_point.png");
	ch_graze_g = LoadGraph("datafile/front/front_graze.png");
	enemymarker_g = LoadGraph("datafile/front/front_enemymarker.png");


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

	//�l�̕\��
	DrawFormatStringToHandle(520, 60, RGB(255, 255, 255), font_front, "%08d", highscore);
	DrawFormatStringToHandle(520, 80, RGB(255, 255, 255), font_front, "%08d", score);
	/*DrawFormatStringToHandle(520, 110, RGB(255, 255, 255), font_front, "%d", player_num);
	DrawFormatStringToHandle(520, 130, RGB(255, 255, 255), font_front, "%d", bomb);*/
	for (int l = 0; l < player_num; ++l) {
		int size[2];
		GetGraphSize(playernum_g, &size[0], &size[1]);
		DrawGraph(520+ (size[0] + 2)*l, 110, playernum_g, TRUE);
	}
	for (int l = 0; l < bomb; ++l) {
		int size[2];
		GetGraphSize(bomb_g, &size[0], &size[1]);
		DrawGraph(520 + (size[0]+2) * l, 130, bomb_g, TRUE);
	}
	DrawFormatStringToHandle(520, 150, RGB(255, 255, 255), font_front, "%1.2f / 4.00", power);
	DrawFormatStringToHandle(520, 170, RGB(255, 255, 255), font_front, "%d", point);
	DrawFormatStringToHandle(520, 190, RGB(255, 255, 255), font_front, "%d", graze);
}