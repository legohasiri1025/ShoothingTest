#include "enemy.h"
#include "define.h"
#include "DxLib.h"
#include "cmath"

int EnemyShotNum = 0;

void enemy::eShot(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	eShotFlag(x, y, color, type, angle, speed);
	eFireShot();
}

int	enemy::eShotFlag(Point_ x, Point_ y, _Color color, Type type, double angle, double speed) {
	int i;
	for (i = 0; i < E_MAX_SHOT; i++) {
		if (!shotflag)
			break;
		if (i == E_MAX_SHOT)
			return -1;


		{
			nx[i] = x;
			ny[i] = y;
			bullet = BulletData[type][color].graph;

			//���A�������ւ̈ړ���
			sx[i] = cos(angle*(PI / 180))*speed;
			sy[i] = sin(angle*(PI / 180))*speed;

			shotflag = true;
			EnemyShotNum++;
		}
	}
	return 0;
}

void enemy::eFireShot() {
	int i, Con, Num;

	// �e�̐������ړ��������J��Ԃ�
	Con = 0;
	Num = EnemyShotNum;
	for (i = 0; i < E_MAX_SHOT; i++)
	{
		// �e�̃f�[�^���L���ȏꍇ�͏���
		if (shotflag)
		{
			// �ړ�����
			nx[i] += sx[i];
			ny[i] += sy[i];

			// ��ʊO�ɏo����e������������
			if ((nx[i] < -20) ||
				(nx[i] > 660) ||
				(ny[i] < -20) ||
				(ny[i] > 500))
			{
				// �f�[�^�̗L���t���O��|��
				shotflag = false;

				// �e�̐������炷
				EnemyShotNum--;
			}

			// �e�̕`��
			{
				int x, y;

				x = nx[i];
				y = ny[i];

				DrawRotaGraph(x, y, 1, 0, bullet, TRUE);
			}

			// ���������e�̐����C���N�������g
			Con++;

			// ���������e�̐����A���݂��Ă���e�̐��Ɠ����ɂȂ����ꍇ�̓��[�v�𔲂���
			if (Num == Con) break;
		}
	}
}


void enemy::eCreateShot01(Point_ x, Point_ y, double speed, double angle, _Color color, Type type, Count_ late = 0) {
	Count_ count = 0;
	eShot(x, y, color, type, angle, speed);
	if (count >= late) {

	}
	count++;
}

void enemy::eCreateShot02(Point_ x, Point_ y, double speed, double angle, double acceleration, double max_speed, _Color color, Type type, Count_ late = 0) {

}
