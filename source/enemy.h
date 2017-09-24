#ifndef _ENEMY_
#define _ENEMY_
#include "define.h"
#include "bullet.h"

extern enum type;

class enemy {
	Point_ x;
	Point_ y;
	int e_id;
	int e_hp;
	int atarix;
	int atariy;
	Count_ outcount;
	Count_ nowcount;
	Graph_ e_graph;
public:
	enemy();
	enemy(const char *id, int hp, type type);

	int GetEnemyX();
	int GetEnemyY();
	int GetEnemyHp();
};

class enemy_shot : public enemy {
private:
	bool flag;
	Point_ nx, ny;
	Point_ sx, sy;
	Graph_ bullet;
public:
	enemy_shot();
	enemy_shot(int id);

	void Shot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	int	ShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	void FireShot();

	void CreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late);
	void CreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late);
};


#endif