#include "bullet.h"
#include "define.h"
#include "DxLib.h"

int BG[Tn][Cn];//’e‰æ‘œ
BULLET BulletData[Tn][Cn] = {
	{ { Big,BG[0][0] },{ Big,BG[0][1] },{ Big,BG[0][2] },{ Big,BG[0][3] },{ Big,BG[0][4] },{ Big,BG[0][5] },{ Big,BG[0][6] },{ Big,BG[0][7] },{ Big,BG[0][8] },{ Big,BG[0][9] },{ Big,BG[0][10] } },
	{ { Medium,BG[1][0] },{ Medium,BG[1][1] },{ Medium,BG[1][2] },{ Medium,BG[1][3] },{ Medium,BG[1][4] },{ Medium,BG[1][5] },{ Medium,BG[1][6] },{ Medium,BG[1][7] },{ Medium,BG[1][8] },{ Medium,BG[1][9] },{ Medium,BG[1][10] } },
	{ { Small,BG[2][0] },{ Small,BG[2][1] },{ Small,BG[2][2] },{ Small,BG[2][3] },{ Small,BG[2][4] },{ Small,BG[2][5] },{ Small,BG[2][6] },{ Small,BG[2][7] },{ Small,BG[2][8] },{ Small,BG[2][9] },{ Small,BG[2][10] } },
	{ { Pixel,BG[3][0] },{ Pixel,BG[3][1] },{ Pixel,BG[3][2] },{ Pixel,BG[3][3] },{ Pixel,BG[3][4] },{ Pixel,BG[3][5] },{ Pixel,BG[3][6] },{ Pixel,BG[3][7] },{ Pixel,BG[3][8] },{ Pixel,BG[3][9] },{ Pixel,BG[3][10] } },
	{ { Uroko,BG[4][0] },{ Uroko,BG[4][1] },{ Uroko,BG[4][2] },{ Uroko,BG[4][3] },{ Uroko,BG[4][4] },{ Uroko,BG[4][5] },{ Uroko,BG[4][6] },{ Uroko,BG[4][7] },{ Uroko,BG[4][8] },{ Uroko,BG[4][9] },{ Uroko,BG[4][10] } },
	{ { Kunai,BG[5][0] },{ Kunai,BG[5][1] },{ Kunai,BG[5][2] },{ Kunai,BG[5][3] },{ Kunai,BG[5][4] },{ Kunai,BG[5][5] },{ Kunai,BG[5][6] },{ Kunai,BG[5][7] },{ Kunai,BG[5][8] },{ Kunai,BG[5][9] },{ Kunai,BG[5][10] } },
	{ { Rice,BG[6][0] },{ Rice,BG[6][1] },{ Rice,BG[6][2] },{ Rice,BG[6][3] },{ Rice,BG[6][4] },{ Rice,BG[6][5] },{ Rice,BG[6][6] },{ Rice,BG[6][7] },{ Rice,BG[6][8] },{ Rice,BG[6][9] },{ Rice,BG[6][10] } },
	{ { Zayaku,BG[7][0] },{ Zayaku,BG[7][1] },{ Zayaku,BG[7][2] },{ Zayaku,BG[7][3] },{ Zayaku,BG[7][4] },{ Zayaku,BG[7][5] },{ Zayaku,BG[7][6] },{ Zayaku,BG[7][7] },{ Zayaku,BG[7][8] },{ Zayaku,BG[7][9] },{ Zayaku,BG[7][10] } },
	{ { Bullet,BG[8][0] },{ Bullet,BG[8][1] },{ Bullet,BG[8][2] },{ Bullet,BG[8][3] },{ Bullet,BG[8][4] },{ Bullet,BG[8][5] },{ Bullet,BG[8][6] },{ Bullet,BG[8][7] },{ Bullet,BG[8][8] },{ Bullet,BG[8][9] },{ Bullet,BG[8][10] } },
	{ { Suiteki,BG[9][0] },{ Suiteki,BG[9][1] },{ Suiteki,BG[9][2] },{ Suiteki,BG[9][3] },{ Suiteki,BG[9][4] },{ Suiteki,BG[9][5] },{ Suiteki,BG[9][6] },{ Suiteki,BG[9][7] },{ Suiteki,BG[9][8] },{ Suiteki,BG[9][9] },{ Suiteki,BG[9][10] } },
	{ { Daen,BG[10][0] },{ Daen,BG[10][1] },{ Daen,BG[10][2] },{ Daen,BG[10][3] },{ Daen,BG[10][4] },{ Daen,BG[10][5] },{ Daen,BG[10][6] },{ Daen,BG[10][7] },{ Daen,BG[10][8] },{ Daen,BG[10][9] },{ Daen,BG[10][10] } },
	{ { Arrow,BG[11][0] },{ Arrow,BG[11][1] },{ Arrow,BG[11][2] },{ Arrow,BG[11][3] },{ Arrow,BG[11][4] },{ Arrow,BG[11][5] },{ Arrow,BG[11][6] },{ Arrow,BG[11][7] },{ Arrow,BG[11][8] },{ Arrow,BG[11][9] },{ Arrow,BG[11][10] } },
	{ { Laser,BG[12][0] },{ Laser,BG[12][1] },{ Laser,BG[12][2] },{ Laser,BG[12][3] },{ Laser,BG[12][4] },{ Laser,BG[12][5] },{ Laser,BG[12][6] },{ Laser,BG[12][7] },{ Laser,BG[12][8] },{ Laser,BG[12][9] },{ Laser,BG[12][10] } },
	{ { Ikari,BG[13][0] },{ Ikari,BG[13][1] },{ Ikari,BG[13][2] },{ Ikari,BG[13][3] },{ Ikari,BG[13][4] },{ Ikari,BG[13][5] },{ Ikari,BG[13][6] },{ Ikari,BG[13][7] },{ Ikari,BG[13][8] },{ Ikari,BG[13][9] },{ Ikari,BG[13][10] } },
	{ { Fire,BG[14][0] },{ Fire,BG[14][1] },{ Fire,BG[14][2] },{ Fire,BG[14][3] },{ Fire,BG[14][4] },{ Fire,BG[14][5] },{ Fire,BG[14][6] },{ Fire,BG[14][7] },{ Fire,BG[14][8] },{ Fire,BG[14][9] },{ Fire,BG[14][10] } },
	{ { Nuclear,BG[15][0] },{ Nuclear,BG[15][1] },{ Nuclear,BG[15][2] },{ Nuclear,BG[15][3] },{ Nuclear,BG[15][4] },{ Nuclear,BG[15][5] },{ Nuclear,BG[15][6] },{ Nuclear,BG[15][7] },{ Nuclear,BG[15][8] },{ Nuclear,BG[15][9] },{ Nuclear,BG[15][10] } },
	{ { Genkotu,BG[16][0] },{ Genkotu,BG[16][1] },{ Genkotu,BG[16][2] },{ Genkotu,BG[16][3] },{ Genkotu,BG[16][4] },{ Genkotu,BG[16][5] },{ Genkotu,BG[16][6] },{ Genkotu,BG[16][7] },{ Genkotu,BG[16][8] },{ Genkotu,BG[16][9] },{ Genkotu,BG[16][10] } },
	{ { Star,BG[17][0] },{ Star,BG[17][1] },{ Star,BG[17][2] },{ Star,BG[17][3] },{ Star,BG[17][4] },{ Star,BG[17][5] },{ Star,BG[17][6] },{ Star,BG[17][7] },{ Star,BG[17][8] },{ Star,BG[17][9] },{ Star,BG[17][10] } },
	{ { Butterfly,BG[18][0] },{ Butterfly,BG[18][1] },{ Butterfly,BG[18][2] },{ Butterfly,BG[18][3] },{ Butterfly,BG[18][4] },{ Butterfly,BG[18][5] },{ Butterfly,BG[18][6] },{ Butterfly,BG[18][7] },{ Butterfly,BG[18][8] },{ Butterfly,BG[18][9] },{ Butterfly,BG[18][10] } },
	{ { Knife,BG[19][0] },{ Knife,BG[19][1] },{ Knife,BG[19][2] },{ Knife,BG[19][3] },{ Knife,BG[19][4] },{ Knife,BG[19][5] },{ Knife,BG[19][6] },{ Knife,BG[19][7] },{ Knife,BG[19][8] },{ Knife,BG[19][9] },{ Knife,BG[19][10] } },
	{ { Heart,BG[20][0] },{ Heart,BG[20][1] },{ Heart,BG[20][2] },{ Heart,BG[20][3] },{ Heart,BG[20][4] },{ Heart,BG[20][5] },{ Heart,BG[20][6] },{ Heart,BG[20][7] },{ Heart,BG[20][8] },{ Heart,BG[20][9] },{ Heart,BG[20][10] } },
	{ { Bara,BG[21][0] },{ Bara,BG[21][1] },{ Bara,BG[21][2] },{ Bara,BG[21][3] },{ Bara,BG[21][4] },{ Bara,BG[21][5] },{ Bara,BG[21][6] },{ Bara,BG[21][7] },{ Bara,BG[21][8] },{ Bara,BG[21][9] },{ Bara,BG[21][10] } },
	{ { Huda,BG[22][0] },{ Huda,BG[22][1] },{ Huda,BG[22][2] },{ Huda,BG[22][3] },{ Huda,BG[22][4] },{ Huda,BG[22][5] },{ Huda,BG[22][6] },{ Huda,BG[22][7] },{ Huda,BG[22][8] },{ Huda,BG[22][9] },{ Huda,BG[22][10] } }
};