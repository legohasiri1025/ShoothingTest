#ifndef _BULLET_
#define _BULLET_
#include "define.h"

void LoadBullet();

enum _Color {
	BLUE,
	RED,
	YELLOW,
	BLACK,
	WHITE,
	GREEN,
	PINK,
	WHITE_BLUE,
	YELLOW_GREEN,
	PURPLE,
	ORANGE,
	Cn = 11
};//11

enum _Size {
	Big = 22,
	Medium1 = 7,
	Medium2 = 7,
	Medium3 = 7,
	Small = 3,
	Pixel = 2,
	Uroko = 3,
	Kunai = 2,
	Rice = 2,
	Zayaku = 2,
	Bullet = 2,
	Suiteki = 3,
	Daen = 4,
	Arrow = 2,
	Laser,
	Ikari = 12,
	Fire = 5,
	Nuclear,
	Genkotu,
	Star = 6,
	Butterfly = 4,
	Knife = 3,
	Heart = 7,
	Bara = 20,
	Huda = 2,
	Tn = 25
};//25

enum Type {
	Big_,
	Medium1_,
	Small_,
	Pixel_,
	Uroko_,
	Kunai_,
	Rice_,
	Zayaku_,
	Bullet_,
	Suiteki_,
	Daen_,
	Arrow_,
	Laser_,
	Ikari_,
	Fire_,
	Nuclear_,
	Genkotu_,
	Star_,
	Butterfly_,
	Knife_,
	Heart_,
	Bara_,
	Huda_,
	Medium2_,
	Medium3_,
	Tn_
};//25

extern Graph_  BG[Tn][Cn];

typedef struct _bullet {
	_Size size;
	Graph_ graph;
}BULLET;

extern BULLET BulletData[Tn][Cn];
#endif