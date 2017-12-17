#include "DxLib.h"
#include "enemy.h"
#include "stage.h"
#include "func.h"
#include "sound.h"
enum type {//b=�� r=�� y=�� g=�� ph=��
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
stage::stage() {
	stageinit();
	stagenum = 1;
}

void stage::stageinit() {
	stagecount = 0;
	stagenum++;
	stageclear = false;
}
enemy *testenemy = new enemy(450, 0, 30, b_meido, 32, 40, 2, 2);
void stage::stage1() {
	stagecount++;
	if (testenemy->updata()) {



		if (stagecount > 60 && stagecount < 300)
			testenemy->move(216, 200, 4.0);

		if (stagecount > 330 && stagecount < 900)
			testenemy->move(100, 100, 90);
		if (stagecount > 900) {
			//delete testenemy;
		}
		else {
			testenemy->updata();
		}
	}
}

void stage::stage2() {
	stagecount++;

}

void stage::stage3() {
	stagecount++;
}

void stage::stage4() {
	stagecount++;
}

void stage::stage5() {
	stagecount++;
}

void stage::stage6() {
	stagecount++;
}

void stage::stageex() {
	stagecount++;
}

void stage::stageupdate() {
	if (key[KEY_INPUT_ADD]==1) {
		stageclear = true;
	}else if (key[KEY_INPUT_SUBTRACT] == 1) {
		stagenum--;
	}

	if (stageclear) {
		/*switch (stagenum) {
		case 1:
			stagenum = 2;
			stageinit();
			break;
		case 2:
			stagenum = 3;
			stageinit();
			break;
		case 3:
			stagenum = 4;
			stageinit();
			break;
		case 4:
			stagenum = 5;
			stageinit();
			break;
		case 5:
			stagenum = 6;
			stageinit();
			break;
		case 6:
			stagenum = 8;
			stageinit();
			break;
		}*/
		stageinit();
	}
	switch (stagenum) {
	case 1:
		stage1();
		break;
	case 2:
		stage2();
		break;
	case 3:
		stage3();
		break;
	case 4:
		stage4();
		break;
	case 5:
		stage5();
		break;
	case 6:
		stage6();
		break;
	case 7:
		stageex();
		break;
	}

#ifdef _DEBUG
	DrawFormatString(0, FIELD_MAX_Y, RGB(255, 255, 255), "stage[%d]", stagenum);
	DrawFormatString(90, FIELD_MAX_Y, RGB(255, 255, 255), "stagecount[%d]", stagecount);
#endif

}