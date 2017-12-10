#include "enemy.h"
#include "define.h"
#include <new>


enum type {
	b_meido,
	b_flower,
	b_fairy,
	r_meido,
	r_flower,
	r_fairy,
	y_flower,
	y_fairy,
	g_flower,
	g_fairy,
	ph_b_flower,
	ph_r_flower,
	ph_g_flower,
	ph_y_flower,
	sunflower,
	ph_sunflower
};

enemy::enemy(int hp, type type) {
	e_hp = hp;

}

enemy::enemy() {

}

int enemy::GetEnemyX() {
	return x;
}

int enemy::GetEnemyY() {
	return y;
}

int enemy::GetEnemyHp() {
	return e_hp;
}

void enemy::setlife(int hp) {
	e_hp = hp;
}