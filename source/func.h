#ifndef _FUNC_
#define _FUNC_
#include "define.h"
#include "bullet.h"


//extern	int		EnemyShotNum;

#define loop(x)	for(int i=0; i < x; ++i)
inline	double	Rand(double min, double max);//—”‚ÌŽæ“¾


inline	int		GetPlayerX();
inline	int		GetPlayerY();
inline	void	SetPlayerX(Point_ x);
inline	void	SetPlayerY(Point_ y);
inline	void	SetSpeed(double speed);
inline	void	SetAngle(double angle);
inline	double	GetAngleEnemyToPlayer(int i);
inline	double	GetAngle(Point_ ax, Point_ ay, Point_ bx, Point_ by);
inline	int		GetEnemyX(int i);
inline	int		GetEnemyY(int i);
inline	int		GetEnemyLife(int i);

inline	void	Shot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
		int		ShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed);
		void	FireShot();
		void	SetMovePosition01(Point_ x, Point_ y, double speed, int i);
		void	SetMovePosition02(Point_ x, Point_ y, int flame, int i);
		void	SetMovePosition03(Point_ x, Point_ y, double weight, double max_speed, int i);

		void	CreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late);
		void	CreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late);

		void	DrawPlayer(Point_ x, Point_ y, Graph_ graph);

inline	void	Wait(Count_ count);
#endif