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

			//ｘ、ｙ方向への移動量
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

	// 弾の数だけ移動処理を繰り返す
	Con = 0;
	Num = EnemyShotNum;
	for (i = 0; i < E_MAX_SHOT; i++)
	{
		// 弾のデータが有効な場合は処理
		if (shotflag)
		{
			// 移動処理
			nx[i] += sx[i];
			ny[i] += sy[i];

			// 画面外に出たら弾情報を消去する
			if ((nx[i] < -20) ||
				(nx[i] > 660) ||
				(ny[i] < -20) ||
				(ny[i] > 500))
			{
				// データの有効フラグを倒す
				shotflag = false;

				// 弾の数を減らす
				EnemyShotNum--;
			}

			// 弾の描画
			{
				int x, y;

				x = nx[i];
				y = ny[i];

				DrawRotaGraph(x, y, 1, 0, bullet, TRUE);
			}

			// 処理した弾の数をインクリメント
			Con++;

			// 処理した弾の数が、存在している弾の数と同じになった場合はループを抜ける
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
