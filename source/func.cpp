#include "func.h"
#include <random>
#include "DxLib.h"
#include "cmath"
using namespace std;

int key[256]; // 0:“ü—Í‚³‚ê‚Ä‚¢‚È‚¢ 1:“ü—Í‚³‚ê‚½uŠÔ 2:“ü—Í‚³‚ê‚Ä‚¢‚é
void inputkey() {
	static char buf[256];
	GetHitKeyStateAll(buf);
	for (int i = 0; i < 256; i++) {
		if (buf[i]) {
			if (key[i] == 0) key[i] = 1;
			else if (key[i] == 1) key[i] = 2;
		}
		else key[i] = 0;
	}
}

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