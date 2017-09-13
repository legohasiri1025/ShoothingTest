#include "func.h"
#include "define.h"
#include "bullet.h"
#include "define.h"
#include <cmath>
#include "DxLib.h"

typedef struct _enemyshot {
	int x, y;//座標
	int sx, sy;//次の座標
	double speed;//スピード
	_Bullet_ bullet;//弾の種類

	double hit_r;
	bool flag;//フラグ
}ENEMY_SHOT;

typedef struct _enemy {
	int x, y;
	int counter, counter2;
	int life;
	double angle;
	int number;
}ENEMY;

typedef struct _player {
	int x, y;
	double speed;
	double hit_r;
	bool life;
}PLAYER;


PLAYER Player;
ENEMY Enemy[ENEMY_MAX];
ENEMY_SHOT Enemy_shot[E_MAX_SHOT];

double Rand(double min, double max) {
	(double)SRand(GetNowCount()*PI);//乱数初期値の設定
	return (double)GetRand(max - min) + min;
}

int GetPlayerX() {
	return Player.x;
}

int GetPlayerY(){
	return Player.y;
}

int GetEnemyX(int i) {
	return Enemy[i].x;
}

int GetEnemyY(int i) {
	return Enemy[i].y;
}

int GetEnemyLife(int i) {
	return Enemy[i].life;
}

void SetPlayerX(Point_ x) {
	Player.x = x;
}

void SetPlayerY(Point_ y) {
	Player.x = y;
}

void SetSpeed(double speed) {

}
void SetAngle(double angle) {

}

double GetAngleEnemyToPlayer(int i) {
	return atan2((double)(Player.y - Enemy[i].y), (double)(Player.x - Enemy[i].x));
}

double GetAngle(Point_ ax, Point_ ay, Point_ bx, Point_ by) {
	return atan2((double)(ay - by), (double)(ax - bx));
}

void DrawPlayer(Point_ x, Point_ y, Graph_ graph){
	DrawRotaGraph(x, y, 1, 0, graph, TRUE);
}

void Wait(Count_ count) {
	for (int i = 0; i < count; i++);
}


int EnemyShotNum = 0;


void Shot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	ShotFlag(x, y, color, type, angle, speed);
	FireShot();
}

int	ShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
		int i;
		for (i = 0; i < E_MAX_SHOT; i++)
			if (!Enemy_shot[i].flag)
				break;
		if (i == E_MAX_SHOT)
			return -1;


		{
			Enemy_shot[i].x = x;
			Enemy_shot[i].y = y;
			Enemy_shot[i].bullet = BulletData[type][color].graph;

			//ｘ、ｙ方向への移動量
			Enemy_shot[i].sx = cos(angle*(PI / 180))*speed;
			Enemy_shot[i].sy = sin(angle*(PI / 180))*speed;

			Enemy_shot[i].flag = true;
			EnemyShotNum++;
		}
		return 0;
	}

void FireShot() {
		int i, Con, Num;

		// 弾の数だけ移動処理を繰り返す
		Con = 0;
		Num = EnemyShotNum;
		for (i = 0; i < E_MAX_SHOT; i++)
		{
			// 弾のデータが有効な場合は処理
			if (Enemy_shot[i].flag)
			{
				// 移動処理
				Enemy_shot[i].x += Enemy_shot[i].sx;
				Enemy_shot[i].y += Enemy_shot[i].sy;

				// 画面外に出たら弾情報を消去する
				if ((Enemy_shot[i].x < -20) ||
					(Enemy_shot[i].x > 660) ||
					(Enemy_shot[i].y < -20) ||
					(Enemy_shot[i].y > 500))
				{
					// データの有効フラグを倒す
					Enemy_shot[i].flag = false;

					// 弾の数を減らす
					EnemyShotNum--;
				}

				// 弾の描画
				{
					int x, y;

					x = Enemy_shot[i].x;
					y = Enemy_shot[i].y;

					DrawRotaGraph(x, y, 1, 0, Enemy_shot[i].bullet, TRUE);
				}

				// 処理した弾の数をインクリメント
				Con++;

				// 処理した弾の数が、存在している弾の数と同じになった場合はループを抜ける
				if (Num == Con) break;
			}
		}
	}


void CreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late = 0) {
	Count_ count = 0;
	Shot(x, y, color, type, angle, speed);
	if (count >= late) {

	}
	count++;
}

void CreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late = 0) {

}

