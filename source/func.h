#ifndef _FUNC_
#define _FUNC_
#include "define.h"
#include "bullet.h"


//extern	int		EnemyShotNum;
extern int key[256];
inline	double	Rand(double min, double max);//—”‚Ìæ“¾
void inputkey();

inline	void	SetSpeed(double speed);
inline	void	SetAngle(double angle);
inline	double	GetAngleEnemyToPlayer(int i);
inline	double	GetAngle(Point_ ax, Point_ ay, Point_ bx, Point_ by);

inline	void	Wait(Count_ count);
#endif