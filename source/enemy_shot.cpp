#include "enemy.h"
#include "define.h"
#include "DxLib.h"
#include "cmath"

int EnemyShotNum = 0;

void enemy_shot::Shot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	ShotFlag(x, y, color, type, angle, speed);
	FireShot();
}

int	enemy_shot::ShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	int i;
	for (i = 0; i < E_MAX_SHOT; i++)
		if (!flag)
			break;
	if (i == E_MAX_SHOT)
		return -1;


	{
		nx = x;
		ny = y;
		bullet = BulletData[type][color].graph;

		//‚˜A‚™•ûŒü‚Ö‚ÌˆÚ“®—Ê
		sx = cos(angle*(PI / 180))*speed;
		sy = sin(angle*(PI / 180))*speed;

		flag = true;
		EnemyShotNum++;
	}
	return 0;
}

void enemy_shot::FireShot() {
	int i, Con, Num;

	// ’e‚Ì”‚¾‚¯ˆÚ“®ˆ—‚ðŒJ‚è•Ô‚·
	Con = 0;
	Num = EnemyShotNum;
	for (i = 0; i < E_MAX_SHOT; i++)
	{
		// ’e‚Ìƒf[ƒ^‚ª—LŒø‚Èê‡‚Íˆ—
		if (flag)
		{
			// ˆÚ“®ˆ—
			nx += sx;
			ny += sy;

			// ‰æ–ÊŠO‚Éo‚½‚ç’eî•ñ‚ðÁ‹Ž‚·‚é
			if ((nx < -20) ||
				(nx > 660) ||
				(ny < -20) ||
				(ny > 500))
			{
				// ƒf[ƒ^‚Ì—LŒøƒtƒ‰ƒO‚ð“|‚·
				flag = false;

				// ’e‚Ì”‚ðŒ¸‚ç‚·
				EnemyShotNum--;
			}

			// ’e‚Ì•`‰æ
			{
				int x, y;

				x = nx;
				y = ny;

				DrawRotaGraph(x, y, 1, 0, bullet, TRUE);
			}

			// ˆ—‚µ‚½’e‚Ì”‚ðƒCƒ“ƒNƒŠƒƒ“ƒg
			Con++;

			// ˆ—‚µ‚½’e‚Ì”‚ªA‘¶Ý‚µ‚Ä‚¢‚é’e‚Ì”‚Æ“¯‚¶‚É‚È‚Á‚½ê‡‚Íƒ‹[ƒv‚ð”²‚¯‚é
			if (Num == Con) break;
		}
	}
}


void enemy_shot::CreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late = 0) {
	Count_ count = 0;
	Shot(x, y, color, type, angle, speed);
	if (count >= late) {

	}
	count++;
}

void enemy_shot::CreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late = 0) {

}