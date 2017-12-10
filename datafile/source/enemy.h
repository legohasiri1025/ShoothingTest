#ifndef _ENEMY_
#define _ENEMY_
#include "define.h"
#include "bullet.h"
#include "player.h"

extern enum type;

class enemy :protected player{
	Point_ x;
	Point_ y;
	int e_id;
	int e_hp;
	int atarix;
	int atariy;
	Count_ outcount;
	Count_ nowcount;
	Graph_ e_graph;

	//shot
	bool shotflag;
	Point_ nx[E_MAX_SHOT], ny[E_MAX_SHOT];//ñ⁄ìIín
	Point_ cx[E_MAX_SHOT], cy[E_MAX_SHOT];//î≠éÀín
	Point_ sx[E_MAX_SHOT], sy[ENEMY_MAX];//ç°
	Graph_ bullet;
public:
	enemy();
	enemy(int hp, type type);

	int GetEnemyX();
	int GetEnemyY();
	int GetEnemyHp();

	void setlife(int hp);

	//shot
	void eShot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	int	 eShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	void eFireShot();

	void eCreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late);
	void eCreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late);
};

/*class enemy_shot : public enemy {
private:
	
public:
	enemy_shot();
	enemy_shot(int id);

	
};*/


#endif