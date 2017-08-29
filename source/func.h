#ifndef _FUNC_
#define _FUNC_
#include "define.h"
#include "bullet.h"


//extern	int		EnemyShotNum;

#define loop(x)	for(int i=0; i < x; ++i)
inline	double	Rand(double min, double max);//—”‚ÌŽæ“¾


inline	int		GetPlayerX();
inline	int		GetPlayerY();
inline	void	SetPlayerX(int x);
inline	void	SetPlayerY(int y);
inline	void	SetSpeed(double speed);
inline	void	SetAngle(double angle);
inline	double	GetAngleEnemyToPlayer(int i);
inline	double	GetAngle(int ax, int ay, int bx, int by);
inline	int		GetEnemyX(int i);
inline	int		GetEnemyY(int i);
inline	int		GetEnemyLife(int i);

inline	void	Shot(int x, int y, _Color color, Type type, double angle, double speed);
		int		ShotFlag(int x, int y, _Color color, Type type, double angle, double speed);
		void	FireShot();
		void	SetMovePosition01(int x, int y, double speed, int i);
		void	SetMovePosition02(int x, int y, int flame, int i);
		void	SetMovePosition03(int x, int y, double weight, double max_speed, int i);

		void	CreateShot01(int x, int y, double speed, double angle, _Color color, Type type, Count_ late);
		void	CreateShot02(int x, int y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late);

		void	DrawPlayer(int x, int y, Graph_ graph);

inline	void	Wait(Count_ count);
#endif