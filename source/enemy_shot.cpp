#include "enemy.h"
#include "define.h"
#include "DxLib.h"
#include "cmath"

int EnemyShotNum = 0;

void enemy::eShot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	eShotFlag(x, y, color, type, angle, speed);
	eFireShot();
}

int	enemy::eShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	int i;
	for (i = 0; i < E_MAX_SHOT; i++) {
		if (!shotflag)
			break;
		if (i == E_MAX_SHOT)
			return -1;


		{
			nx[i] = x;
			ny[i] = y;
			bullet = BulletData[type][color].graph;

			//‚˜A‚™•ûŒü‚Ö‚ÌˆÚ“®—Ê
			sx[i] = cos(angle*(PI / 180))*speed;
			sy[i] = sin(angle*(PI / 180))*speed;

			shotflag = true;
			EnemyShotNum++;
		}
	}
	return 0;
}

void enemy::eFireShot() {
	int i, Con, Num;

	// ’e‚Ì”‚¾‚¯ˆÚ“®ˆ—‚ðŒJ‚è•Ô‚·
	Con = 0;
	Num = EnemyShotNum;
	for (i = 0; i < E_MAX_SHOT; i++)
	{
		// ’e‚Ìƒf[ƒ^‚ª—LŒø‚Èê‡‚Íˆ—
		if (shotflag)
		{
			// ˆÚ“®ˆ—
			nx[i] += sx[i];
			ny[i] += sy[i];

			// ‰æ–ÊŠO‚Éo‚½‚ç’eî•ñ‚ðÁ‹Ž‚·‚é
			if ((nx[i] < -20) ||
				(nx[i] > 660) ||
				(ny[i] < -20) ||
				(ny[i] > 500))
			{
				// ƒf[ƒ^‚Ì—LŒøƒtƒ‰ƒO‚ð“|‚·
				shotflag = false;

				// ’e‚Ì”‚ðŒ¸‚ç‚·
				EnemyShotNum--;
			}

			// ’e‚Ì•`‰æ
			{
				int x, y;

				x = nx[i];
				y = ny[i];

				DrawRotaGraph(x, y, 1, 0, bullet, TRUE);
			}

			// ˆ—‚µ‚½’e‚Ì”‚ðƒCƒ“ƒNƒŠƒƒ“ƒg
			Con++;

			// ˆ—‚µ‚½’e‚Ì”‚ªA‘¶Ý‚µ‚Ä‚¢‚é’e‚Ì”‚Æ“¯‚¶‚É‚È‚Á‚½ê‡‚Íƒ‹[ƒv‚ð”²‚¯‚é
			if (Num == Con) break;
		}
	}
}


void enemy::eCreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late = 0) {
	Count_ count = 0;
	eShot(x, y, color, type, angle, speed);
	if (count >= late) {

	}
	count++;
}

void enemy::eCreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late = 0) {

}
