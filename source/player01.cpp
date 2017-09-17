//—ì–²
#include "define.h"
#include "player01.h"
#include "player.h"
#include "DxLib.h"

player::player() {
	x = FIELD_CENTER_X;
	y = FIELD_MAX_Y - 60;
	bomb = DEFAULT_BOMB;
	player_num = DEFAULT_PLAYER;
	power = 1.00;
	point = 10000;
	speed = SPEED;
	slow_speed = SLOW;
	count1 = 0;
	count2 = 0;
	i = 0;
	j = 0;
	life = true;
	right = false;
	left = false;
	up = false;
	down = false;
	slow = false;
	graphic[24] = 0;
	LoadDivGraph("../player/player01/player.png", 24, 8, 3, 32, 48, graphic);
}

void player::move() {

	if (x <= FIELD_MIN_X + 32) {
		x = FIELD_MIN_X + 32;
	}
	if (x >= FIELD_MAX_X - 32) {
		x = FIELD_MAX_X + 32;
	}
	if (y <= FIELD_MIN_Y + 32) {
		y = FIELD_MIN_Y + 32;
	}
	if (y >= FIELD_MAX_Y - 32) {
		y = FIELD_MAX_Y - 32;
	}



	if (CheckHitKey(KEY_INPUT_LSHIFT) != 0) {
		slow = true;
	}
	else {
		slow = false;
	}



	if ((CheckHitKey(KEY_INPUT_UP) != 0)|| (CheckHitKey(KEY_INPUT_NUMPAD8) != 0)) {

		if ((CheckHitKey(KEY_INPUT_RIGHT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD6) != 0)) {
			right = true;
			left = false;
		}
		else if ((CheckHitKey(KEY_INPUT_LEFT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD4) != 0)) {
			left = true;
			right = false;
		}
		else {
			left = false;
			right = false;
		}

		up = true;
		down = false;
	}

	else if ((CheckHitKey(KEY_INPUT_DOWN) != 0)||(CheckHitKey(KEY_INPUT_NUMPAD2)!=0)) {

		if ((CheckHitKey(KEY_INPUT_RIGHT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD6) != 0)) {
			right = true;
			left = false;
		}
		else if ((CheckHitKey(KEY_INPUT_LEFT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD4) != 0)) {
			left = true;
			right = false;
		}
		else {
			left = false;
			right = false;
		}

		down = true;
		up = false;
	}

	else if ((CheckHitKey(KEY_INPUT_LEFT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD4) != 0)) {

		if ((CheckHitKey(KEY_INPUT_UP) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD8) != 0)) {
			up = true;
			down = false;
		}
		else if ((CheckHitKey(KEY_INPUT_DOWN) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD2) != 0)) {
			down = true;
			up = false;
		}
		else {
			up = false;
			down = false;
		}

		left = true;
		right = false;
	}

	else if ((CheckHitKey(KEY_INPUT_RIGHT) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD6) != 0)) {

		if ((CheckHitKey(KEY_INPUT_UP) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD8) != 0)) {
			up = true;
			down = false;
		}
		else if ((CheckHitKey(KEY_INPUT_DOWN) != 0) || (CheckHitKey(KEY_INPUT_NUMPAD2) != 0)) {
			down = true;
			up = false;
		}
		else {
			up = false;
			down = false;
		}

		right = true;
		left = false;
	}
	else if (CheckHitKey(KEY_INPUT_NUMPAD1) != 0) {
		left = true;
		down = true;
		right = false;
		up = false;
	}

	else if (CheckHitKey(KEY_INPUT_NUMPAD3) != 0) {
		right = true;
		down = true;
		left = false;
		up = false;
	}

	else if (CheckHitKey(KEY_INPUT_NUMPAD7) != 0) {
		left = true;
		up = true;
		right = false;
		down = false;
	}

	else if (CheckHitKey(KEY_INPUT_NUMPAD9) != 0) {
		right = true;
		up = true;
		left = false;
		down = false;
	}
	else {
		right = false;
		left = false;
		up = false;
		down = false;
	}


	if (!slow) {
		if (right)
			x += SPEED;
		if (left)
			x-= SPEED;
		if (up)
			y-= SPEED;
		if (down)
			y+= SPEED;
	}
	else {
		if (right)
			x += SLOW;
		if (left)
			x -= SLOW;
		if (up)
			y -= SLOW;
		if (down)
			y += SLOW;
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
	
	DrawRotaGraph(x, y, 1, 0, graphic[j], TRUE);
	//DrawPixel(x, y, GetColor(255, 255, 255));
	DrawFormatString(0, 0, RGB(255, 255, 255), "[%d],[%d]", j, count1);
	DrawFormatString(0, 20, RGB(255, 255, 255), "[%d],[%d]", x, y);
}


shot::shot() {
	
	shotspeed = SHOTSPEED;
	subspeed = SUBSHOTSPEED;
	m_power = POWER;
	s_power = SUBPOWER;

	mainshotgr = LoadGraph("../player/player01/shot.png");
	optionshotgr = LoadGraph("../player/player01/optionshot.png");
	optionshotgr = LoadGraph("../player/player01/option.png");
	shotse = LoadSoundMem("../se/shot.wav");
	shotcount1 = 0;
	shotcount2 = 0;

	for (int i = 0; i < P_MAX_SHOT; i++) {
		p_shot[i][0] = false;
		p_shot[i][1] = false;
		sx[i][0] = 0;
		sy[i][0] = 0;
		sx[i][1] = 0;
		sy[i][1] = 0;
	}
}

void shot::mainshot1() {
	shotcount1++;
	if (shotcount1 % 10 == 0) {
		if (CheckHitKey(KEY_INPUT_Z) != 0) {
			PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
			DrawString(0, 40, "Z‰Ÿ‰º’†", RGB(255, 255, 255));
			for (int i = 0; i < P_MAX_SHOT; i++) {
				if (!p_shot[i][0]) {
					sx[i][0] = x + 12;
					sy[i][0] = y - 40;
					p_shot[i][0] = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < P_MAX_SHOT; i++) {
		if (p_shot[i][0]) {
			sy[i][0] -= shotspeed;
			if (sx[i][0] > FIELD_MAX_X || sx[i][0] < FIELD_MIN_X
				|| sy[i][0] < FIELD_MIN_Y || sy[i][0] > FIELD_MAX_Y) {
				p_shot[i][0] = false;
			}
			DrawRotaGraph(sx[i][0], sy[i][0], 1, PI, mainshotgr, TRUE);
		}
	}
}

void shot::mainshot2() {
	shotcount2++;
	if (shotcount2 % 10) {
		if (CheckHitKey(KEY_INPUT_Z) != 0) {
			for (int i = 0; i < P_MAX_SHOT; i++) {
				if (!p_shot[i][1]) {
					sx[i][1] = x - 12;
					sy[i][1] = y - 40;
					p_shot[i][1] = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < P_MAX_SHOT; i++) {
		if (p_shot[i][1]) {
			sy[i][1] -= shotspeed;
			if (sx[i][1] > FIELD_MAX_X || sx[i][1] < FIELD_MIN_X
				|| sy[i][1] < FIELD_MIN_Y || sy[i][1] > FIELD_MAX_Y) {
				p_shot[i][1] = false;
			}
			DrawRotaGraph(sx[i][1], sy[i][1], 1, PI / 2, mainshotgr, TRUE);
		}
	}
}