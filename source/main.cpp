#include "DxLib.h"
#include "player.h"
#include "front.h"
#include "sound.h"
#include "font.h"
#include <time.h>
#include <string>

int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
double Fps = 0.00;
double fps() {
	if (FpsTime_i == 0)
		FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
	if (FpsTime_i == 29) {
		FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
		Fps = 1000.00f / ((FpsTime[1] - FpsTime[0]) / 29.00f);//���肵���l����fps���v�Z
		FpsTime_i = 0;//�J�E���g��������
	}
	else
		FpsTime_i++;//���݉����ڂ��J�E���g

	return Fps;
}

void mswindow() {
	//MessageBox(NULL,"�E�B���h�E���[�h��I��ł�������","�����{�_�`",MB_
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	char rate = 2;
	BOOL FULLSCREEN = 1;
	ChangeWindowMode(FULLSCREEN);
	SetMainWindowText("�����{�_�`�`The Pecten Maiden.  Ver.��");
	// �c�w���C�u�����̏�����
	if (DxLib_Init() == -1) return -1;
	SetWindowSizeExtendRate(rate, rate);
	// ����ʂ��g�p
	SetDrawScreen(DX_SCREEN_BACK);
	player reimutest;
	front front;
	Count_ f=0;
	soundload();
	fontload();
	//�o�[�W����
	int mj = 1, mn = 0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		f++;
		front.draw();
		reimutest.updata();
		playbgm(bgm1_1);
		DrawFormatStringToHandle(540, 460, RGB(255, 255, 255),font_fps,"%02.2f fps", fps());

		
		//debug
#ifdef _DEBUG
		DrawFormatString(240, 0, RGB(255, 255, 255), "ver:%d.%d.%x.%x",mj,mn,__TIME__ ,__DATE__);
#endif
	}
	// �c�w���C�u�����̎g�p�I��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}