#include "DxLib.h"
#include "enemy.h"
#include "define.h"
#include <new>
#include <cmath>


enum type {//b=青 r=赤 y=黄 g=緑 ph=紫
	b_meido,
	b_flower,
	b_fairy,
	r_meido,
	r_flower,
	r_fairy,
	y_flower,
	y_fairy,
	g_flower,
	g_fairy,
	ph_b_flower,
	ph_r_flower,
	ph_g_flower,
	ph_y_flower,
	sunflower,
	ph_sunflower
};


enemy::enemy(Point_ ini_x, Point_ ini_y, int hp, type type,int atari_r,Point_ score_,/*itemdata*/int power, int point, int power_b, int full, int spell, int spell_p, int extend, int extend_p, bool enemy) {
	old_x = x;
	now_x = x;
	enemy::x = ini_x;
	enemy::y = ini_y;
	atarix = atari_r;
	atariy = atari_r;
	score = score_;
	count = 0;

	angle_ = 0;
	speed_ = 0;
	//drawcount = 0;
	//hp設定
	e_hp = hp;
	movecount = 0;
	enemyflag = true;
	movenow = false;
	//敵画像の読み込み
	switch (type) {
	case b_meido:
		LoadDivGraph("datafile/enemy/b_meido.dds", 12, 4, 3, 48, 38, &e_graph[12]);
		break;
	case r_meido:
		LoadDivGraph("datafile/enemy/r_meido.dds", 12, 4, 3, 48, 38, &e_graph[12]);
		break;
	default:
		LoadGraph("datafile/dummy.dds");
	}

	//アイテム所持数
	i_power =power;
	i_point = point;
	i_power_b = power_b;
	i_full = full;
	i_spell = spell;
	i_spell_p = spell_p;
	i_extend = extend;
	i_extend_p = extend_p;
}

Point_ enemy::GetEnemyX() {
	return x;
}

Point_ enemy::GetEnemyY() {
	return y;
}

double enemy::GetEnemyHp() {
	return e_hp;
}

void enemy::setlife(int hp) {
	e_hp = hp;
}
void enemy::move(Point_ x, Point_ y, Count_ count) {//すべて整数
	
	switch(movecount) {
	case 0:
		
		speed_ = (sqrt((x - enemy::x)* (x - enemy::x) + (y - enemy::y)*(y - enemy::y)) / count);//距離を時間で割って速さを求める
		break;
	default:
		movenow = true;
		angle_ = atan2(y - enemy::y, x - enemy::x);
		if (!(enemy::x >= speed_-ceil(x)&& enemy::x <= floor(x)+ speed_)) {
			enemy::x += cos(angle_)*speed_;
		}
		else {
			enemy::x = x;
		}
		if (!(enemy::y >= speed_ -ceil(y) && enemy::y <= floor(y)+ speed_)) {
			enemy::y += sin(angle_)*speed_;
		}
		else {
			enemy::y = y;
		}
	}
	movecount++;
	if ((enemy::x == x&&enemy::y == y)) {
		movenow = false;
		movecount = 0;
	}
	else {
		movenow = true;
	}
	DrawFormatStringF((float)enemy::x, (float)enemy::y + atarix+16, RGB(255, 255, 255), "[%.2f]", speed_);
}

void enemy::move(Point_ x, Point_ y, double speed) {//第三引数は浮動小数点
	static Point_ xx, yy;
	switch (movecount) {
	case 0:
		xx = x;
		yy = y;
		speed_ = speed;
		break;
	default:
		movenow = true;
		angle_ = atan2(yy - enemy::y, xx - enemy::x);
		if (!(enemy::x >= speed_ - ceil(xx) && enemy::x <= floor(xx) + speed_)) {
			enemy::x += cos(angle_)*speed_;
		}
		else {
			enemy::x = xx;
		}
		if (!(enemy::y >= speed_ - ceil(yy) && enemy::y <= floor(yy) + speed_)) {
			enemy::y += sin(angle_)*speed_;
		}
		else {
			enemy::y = yy;
		}
	}
	movecount++;
	if ((enemy::x == xx&&enemy::y == yy)) {
		movenow = false;
	}
	else {
		movenow = true;
	}
	DrawFormatStringF((float)enemy::x, (float)enemy::y + atarix + 16, RGB(255, 255, 255), "[%.2f]", speed_);
}


int enemy::move_lr() {//0=まっすぐ　1=右　2=左
	/*if (drawcount % 2== 1) {

	}
	else if (drawcount % 2 == 0) {

	}*/

	old_x = x;
	if (old_x == now_x) {
		return 0;
	}
	else if(old_x>now_x){
		return 1;
	}
	else {
		return 2;
	}
	now_x = x;
}

void enemy::draw() {
	int grx = 0, gry = 0;
	int i = 0;

	if (move_lr() == 0) {
		if (i < 4) {
			i = 0;
		}

	}
	if (move_lr() == 1) {
		if (i < 4) {
			i = 5;
		}
		else if (i < 12) {
			i = 9;
		}

		if (6 % i == 0) {
			i++;
		}
	}


	GetGraphSize(e_graph[0], &grx, &gry);
	if (move_lr() == 2) {
		DrawTurnGraphF((float)x - (grx / 2), (float)y - (gry / 2), e_graph[i], TRUE);
	}
	else {
		DrawGraphF((float)x - (grx / 2), (float)y - (gry / 2), e_graph[i], TRUE);
	}
}

void enemy::effect() {

}

void enemy::deth() {
	effect();
	for (int a = 0; a < P_MAX_SHOT; a++) {
		for (int w = 0; w < 2; w++) {
			p_shot[a][w] = false;
		}
	}
	score += score;
}

bool enemy::updata() {
	count++;
	int color = GetColor(255, 255, 255);
#ifdef _DEBUG
	DrawFormatString(260, FIELD_MAX_Y, RGB(255, 255, 255), "[x][y]=[%.1f][%.1f]", enemy::x, enemy::y);
	DrawFormatStringF((float)enemy::x, (float)enemy::y + +atarix+36, RGB(255, 255, 255), "[%.2f]", e_hp);
	DrawCircleAA((float)enemy::x, (float)enemy::y, (float)atarix, 16,color);
#endif
	if (e_hp > 0) {
		if (enemy::x <- 16 || enemy::x > 512 || enemy::y < -16 || enemy::y>512) {
			enemyflag = false;
			
		}
		for (int i = 0; i < P_MAX_SHOT; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (player::p_shot[i][j]) {
					if (enemy::x-atarix<player::sx[i][j]-atarix_main&&enemy::x + atarix>player::sx[i][j] + atarix_main) {
						p_shot[i][j] = false;
						color = GetColor(0, 255, 255);
						e_hp -= m_power;
					}
					else {
						color = GetColor(255, 0, 0);
					}
				}
			}
		}
		draw();
		return true;
	}
	else {
		deth();
		return false;
	}
}

enemy::~enemy() {

}