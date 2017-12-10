//—ì–²
#include "define.h"
#include "player01.h"
#include "player.h"
#include "DxLib.h"
#include "sound.h"
#include <cmath>

player::player()
	:px(228), py(405),score(0),bomb(DEFAULT_BOMB), player_num(DEFAULT_PLAYER), power(1.00), point(10000), count1(0), graze(0),count2(0), i(0), j(0)
{
	/*px = 228;
	py = 405;
	bomb = DEFAULT_BOMB;
	player_num = DEFAULT_PLAYER;
	power = 1.00;
	point = 10000;
	speed = SPEED;
	slow_speed = SLOW;
	count1=0;
	count2=0;
	i=0;
	j=0;*/
	life = true;
	right = false;
	left = false;
	up = false;
	down = false;
	slow = false;
	graphic[24] = 0;
	LoadDivGraph("player/player01/player.png", 24, 8, 3, 32, 48, graphic);
	slow_effe = LoadGraph("player/player-slow-eff.png");
	if (highscore <= score) {
		highscore = score;
	}
	else {
		highscore = 100000;
	}
	//shot
	shotspeed = SHOTSPEED;
	subspeed = SUBSHOTSPEED;
	m_power = POWER;
	s_power = SUBPOWER;
	span = SPAN;

	mainshotgr = LoadGraph("player/player01/shot.png");
	optionshotgr = LoadGraph("player/player01/optionshot.png");
	optionshotgr = LoadGraph("player/player01/option.png");

	shotcount1 = 0;
	shotcount2 = 0;
	shotkey = false;

	for (int i = 0; i < P_MAX_SHOT; i++) {
		for (int j = 0; j < 2; j++) {
			p_shot[i][j] = false;
			hit[i][j] = false;
			sx[i][j] = px;
			sy[i][j] = py;
		}
	}
}

void player::move() {

	
	if (CheckHitKey(KEY_INPUT_LSHIFT) != 0) {
		slow = true;
	}
	else {
		slow = false;
	}

	slow ? speed = SLOW : speed = SPEED;

	if (CheckHitKey(KEY_INPUT_UP) != 0 || CheckHitKey(KEY_INPUT_NUMPAD8) != 0) {
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD4) != 0) {
			left = true;
			right = false;
		}

		else if (CheckHitKey(KEY_INPUT_RIGHT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD6) != 0) {
			left = false;
			right = true;
		}
		else {
			left = false;
			right = false;
		}

		up = true;
		down = false;
	}

	else if (CheckHitKey(KEY_INPUT_DOWN) != 0 || CheckHitKey(KEY_INPUT_NUMPAD2) != 0) {
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD4) != 0) {
			left = true;
			right = false;
		}


		else if (CheckHitKey(KEY_INPUT_RIGHT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD6) != 0) {
			left = false;
			right = true;
		}
		else {
			left = false;
			right = false;
		}

		up = false;
		down = true;
	}

	else if (CheckHitKey(KEY_INPUT_LEFT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD4) != 0) {
		if (CheckHitKey(KEY_INPUT_UP) != 0 || CheckHitKey(KEY_INPUT_NUMPAD8) != 0) {
			up = true;
			down = false;
		}

		else if (CheckHitKey(KEY_INPUT_DOWN) != 0 || CheckHitKey(KEY_INPUT_NUMPAD2) != 0) {
			up = false;
			down = true;
		}
		else {
			up = false;
			down = false;
		}

		left = true;
		right = false;
	}

	else if (CheckHitKey(KEY_INPUT_RIGHT) != 0 || CheckHitKey(KEY_INPUT_NUMPAD6) != 0) {
		if (CheckHitKey(KEY_INPUT_UP) != 0 || CheckHitKey(KEY_INPUT_NUMPAD8) != 0) {
			up = true;
			down = false;
		}

		else if (CheckHitKey(KEY_INPUT_DOWN) != 0 || CheckHitKey(KEY_INPUT_NUMPAD2) != 0) {
			up = false;
			down = true;
		}
		else {
			up = false;
			down = false;
		}
		left = false;
		right = true;
	}
	else {
		up = false;
		down = false;
		left = false;
		right = false;
	}

	if (CheckHitKey(KEY_INPUT_NUMPAD1) != 0) {
		up = false;
		down = true;
		left = true;
		right = false;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD3) != 0) {
		up = false;
		down = true;
		left = false;
		right = true;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD7) != 0) {
		up = true;
		down = false;
		left = true;
		right = false;
	}
	if (CheckHitKey(KEY_INPUT_NUMPAD9) != 0) {
		up = true;
		down = false;
		left = false;
		right = true;
	}

	/*if (px < FIELD_MIN_X + 32) {
		px = FIELD_MIN_X + 32;
	}
	if (px >= FIELD_MAX_X - 32) {
		px = FIELD_MAX_X - 32;
	}
	if (py <= FIELD_MIN_Y + 32) {
		py = FIELD_MIN_Y + 32;
	}
	if (py >= FIELD_MAX_Y - 32) {
		py = FIELD_MAX_Y - 32;
	}*/
	


	if (up) {
		py -= speed;
	}
	if (down) {
		py += speed;
	}
	if (left) {
		px -= speed;
	}
	if (right) {
		px += speed;
	}

	if (px < FIELD_MIN_X + 24) {
		px = FIELD_MIN_X + 24;
	}
	if (px > FIELD_MAX_X - 24) {
		px = FIELD_MAX_X - 24;
	}
	if (py < FIELD_MIN_Y + 24) {
		py = FIELD_MIN_Y + 24;
	}
	if (py > FIELD_MAX_Y - 24) {
		py = FIELD_MAX_Y - 24;
	}
}

void player::draw() {
	count1++;
	if (!left && !right) {
		if (j > 7)
			j = 0;
	}
	if (left) {
		if (j < 8) {
			j = 8;
		}
		if (j > 14) {
			j = 12;
		}
	}
	else if (right) {
		if (j < 16) {
			j = 16;
		}
		if (j > 22) {
			j = 20;
		}
	}
	if (count1 % 6 == 0) {
		j++;
	}

	DrawRotaGraph(px, py, 1, 0, graphic[j], TRUE);
	if (slow) {
		i++;
		DrawRotaGraph(px, py, 1, i *(4*(PI/180)), slow_effe, TRUE);
		DrawRotaGraph(px, py, 1, -1*(i *(4*(PI/180))), slow_effe, TRUE);
	}

#ifdef _DEBUG
	DrawFormatString(0, 0, RGB(255, 255, 255), "[%d],[%d]", j, count1);
	DrawFormatString(120, 0, RGB(255, 255, 255), "[%d],[%d]", px, py);
	//if (p_shot[0][0])
	//	DrawString(0, 60, "[0][0]‚Ítrue", RGB(255, 255, 255));
	//if (p_shot[20][0])
	//	DrawString(0, 80, "[20][0]‚Ítrue", RGB(255, 255, 255));
	DrawCircle(px, py,ATARI_R, RGB(255,0,0), TRUE);
#endif
}


/*shot::shot() {

shotspeed = SHOTSPEED;
subspeed = SUBSHOTSPEED;
m_power = POWER;
s_power = SUBPOWER;
span = SPAN;

mainshotgr = LoadGraph("ShoothingTest/player/player01/shot.png");
optionshotgr = LoadGraph("ShoothingTest/player/player01/optionshot.png");
optionshotgr = LoadGraph("ShoothingTest/player/player01/option.png");
shotse = LoadSoundMem("../se/shot.wav");
shotcount1 = 0;
shotcount2 = 0;

for (int i = 0; i < P_MAX_SHOT; i++) {
p_shot[i][0] = false;
p_shot[i][1] = false;
hit[i][0] = false;
hit[i][1] = false;
}
}*/

bool player::shot_key() {
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		if (shotcount1 % SPAN == 0) {

			//DrawString(0, 40, "Z", RGB(255, 255, 255));

			return true;
		}
		else {
			return false;
		}
	}
	else {
		shotcount1 = SPAN - 1;
		return false;
	}
}

void player::mainshot1() {
	int k;
	for (k = 0; k < P_MAX_SHOT; ++k) {
		if (shot_key()) {
			if (!p_shot[k][0]) {
				playse(shotse);
				p_shot[k][0] = true;
				sx[k][0] = px - 16;
				sy[k][0] = py - 16;
				break;
			}
			else {
				continue;
			}
		}
	}
	for (k = 0; k < P_MAX_SHOT; ++k) {
		if (!p_shot[k][0]) {
			continue;
		}
		else {
			if (sy[k][0] < 0) {
				p_shot[k][0] = false;
			}
			else {
				sy[k][0] -= SHOTSPEED;
				DrawRotaGraph(sx[k][0], sy[k][0], 1, 3*PI/2, mainshotgr, TRUE);
			}
		}
	}
}

void player::mainshot2() {
	int k;
	for (k = 0; k < P_MAX_SHOT; ++k) {
		if (shot_key()) {
			if (!p_shot[k][1]) {
				p_shot[k][1] = true;
				sx[k][1] = px + 16;
				sy[k][1] = py - 16;
				break;
			}
			else {
				continue;
			}
		}
	}
	for (k = 0; k < P_MAX_SHOT; ++k) {
		if (!p_shot[k][1]) {
			continue;
		}
		else {
			if (sy[k][1] < 0) {
				p_shot[k][1] = false;
			}
			else {
				sy[k][1] -= SHOTSPEED;
				DrawRotaGraph(sx[k][1], sy[k][1], 1, 3 * PI / 2, mainshotgr, TRUE);
			}
		}
	}

}

void player::optionshot() {

}

void player::updata() {
	move();
	draw();


	shotcount1++;
	shot_key();
	mainshot1();
	mainshot2();
	optionshot();
}


int player::GetPlayerX() {
	return px;
}

int player::GetPlayerY() {
	return py;
}

void player::SetPlayerX(Point_ x) {
	px = x;
}

void player::SetPlayerY(Point_ y) {
	px = y;
}