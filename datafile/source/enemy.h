#ifndef _ENEMY_
#define _ENEMY_
#include "define.h"
#include "bullet.h"
#include "player.h"

extern enum type;



class enemy :protected player{
	Point_ x;
	Point_ y;
	Point_ old_x, now_x;

	int e_id;
	int e_hp;
	Point_ score;

	int atarix;
	int atariy;
	Count_ count;
	//Count_ drawcount;
	Graph_ e_graph[12];

	bool enemyflag;
	int i_power;
	int i_point;
	int i_power_b;
	int i_full;
	int i_spell;
	int i_spell_p;
	int i_extend;
	int i_extend_p;

	//shot
	bool shotflag;
	Point_ nx[E_MAX_SHOT], ny[E_MAX_SHOT];//目的地
	Point_ cx[E_MAX_SHOT], cy[E_MAX_SHOT];//発射地
	Point_ sx[E_MAX_SHOT], sy[ENEMY_MAX];//今
	Graph_ bullet;
public:
	enemy(Point_ ini_x,Point_ ini_y,int hp, type type,int atari_r, Point_ score_,/*itemdata*/int power, int point, int power_b = 0, int full = 0, int spell = 0, int spell_p = 0, int extend = 0, int extend_p = 0, bool enemy = true);

	int GetEnemyX();
	int GetEnemyY();
	int GetEnemyHp();

	void setlife(int hp);
	int move_lr();//動いている方向を返す{0=まっすぐ、1=右、2=左}
	void move(Point_ x, Point_ y, Count_ fleam, Count_ start, Count_ end,Count_ count);//所要時間で設定
	void move(Point_ x, Point_ y, double speed, Count_ start, Count_ end,Count_ count);//スピードで設定
	void effect();

	void deth();


	//shot
	void eShot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	int	 eShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
	void eFireShot();

	void eCreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late);
	void eCreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late);

	//処理系
	void draw();
	bool updata();
	~enemy();
};

/*class enemy_shot : public enemy {
private:
	
public:
	enemy_shot();
	enemy_shot(int id);

	
};*/


#endif