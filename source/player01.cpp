//—ì–²
#include "define.h"
#include "player01.h"
#include "player.h"
#include "DxLib.h"

player::player()
	:px(228),py(405),bomb(DEFAULT_BOMB),player_num(DEFAULT_PLAYER),power(1.00),point(10000),speed(SPEED),slow_speed(SLOW)
	,count1(0),count2(0),i(0),j(0)
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
	LoadDivGraph("../player/player01/player.png", 24, 8, 3, 32, 48, graphic);
	slow_effe = LoadGraph("../player/player-slow-eff.png");
}

void player::move() {

	if (px <= FIELD_MIN_X + 32) {
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
			px += SPEED;
		if (left)
			px-= SPEED;
		if (up)
			py-= SPEED;
		if (down)
			py+= SPEED;
	}
	else {
		if (right)
			px += SLOW;
		if (left)
			px -= SLOW;
		if (up)
			py -= SLOW;
		if (down)
			py += SLOW;
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
		DrawRotaGraph(px, py, 1, i / 8, slow_effe, TRUE);
		DrawRotaGraph(px, py, 1, i / -8, slow_effe, TRUE);
	}
	//DrawPixel(x, y, GetColor(255, 255, 255));
	DrawFormatString(0, 0, RGB(255, 255, 255), "[%d],[%d]", j, count1);
	DrawFormatString(0, 20, RGB(255, 255, 255), "[%d],[%d]", px, py);
}


shot::shot() {
	
	shotspeed = SHOTSPEED;
	subspeed = SUBSHOTSPEED;
	m_power = POWER;
	s_power = SUBPOWER;
	span = SPAN;

	mainshotgr = LoadGraph("../player/player01/shot.png");
	optionshotgr = LoadGraph("../player/player01/optionshot.png");
	optionshotgr = LoadGraph("../player/player01/option.png");
	shotse = LoadSoundMem("../se/shot.wav");
	shotcount1 = 0;
	shotcount2 = 0;

	for (int i = 0; i < P_MAX_SHOT; i++) {
		p_shot[i][0] = false;
		p_shot[i][1] = false;
		hit[i][0] = false;
		hit[i][1] = false;
	}
}

void shot::mainshot1() {
	int k;

	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		shotcount1++;
		if (shotcount1 % span == 0) {
			PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
			for (k = 0; k < P_MAX_SHOT; k++) {
				if (!p_shot[k][0]) {
					break;
				}
			}
			if (k != P_MAX_SHOT) {
				sx[k][0] = &px + 12;
				sy[k][0] = &py - 40;
				p_shot[k][0] = true;
			}
		}
	}
	else {
		shotcount1 = 9;
	}

	for (k = 0; k < P_MAX_SHOT; k++) {
		if (!p_shot[k][0]) {
			continue;
		}
		else {
			DrawRotaGraph(*sx[k][0], *sy[k][0], 1, 0, mainshotgr, TRUE);
		}
		sy[k][0] -= shotspeed;
		if (sy[k][0] < 0) {
			p_shot[k][0] = false;
		}
	}
	DrawFormatString(0, 40, GetColor(255, 255, 255), "[%d][%d]", *sx, *sy);
}

void shot::mainshot2() {
	int k;
	for (k = 0; k < P_MAX_SHOT; k++) {
		if (!p_shot[k][1]) {
			continue;
		}
		else {
			DrawRotaGraph(*sx[k][1], *sy[k][1], 1, 0, mainshotgr, TRUE);
		}
		sy[k][1] -= shotspeed;
		if (sy[k][1] < 0) {
			p_shot[k][1] = false;
		}
	}

	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		shotcount2++;
		if (shotcount2 % span == 0) {
			PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
			for (k = 0; k < P_MAX_SHOT; k++) {
				if (!p_shot[k][0]) {
					break;
				}
			}
			if (k != P_MAX_SHOT) {
				sx[k][1] = &px - 12;
				sy[k][1] = &py - 40;
				p_shot[k][1] = true;
			}
		}
	}
	else {
		shotcount2 = 9;
	}
}