#include "func.h"
#include <random>
#include "DxLib.h"
#include "cmath"
using namespace std;

double Rand(double min, double max) {
	random_device rnd;
	mt19937 mt(rnd());
	uniform_real_distribution<> rand(min, max);
	return rand(mt);
}



void SetSpeed(double speed) {

}
void SetAngle(double angle) {

}



double GetAngle(Point_ ax, Point_ ay, Point_ bx, Point_ by) {
	return atan2((double)(ay - by), (double)(ax - bx));
}

void Wait(Count_ count) {
	int i = 0;
	while (i < count) {
		i++;
	}
}