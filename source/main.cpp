#include "DxLib.h"
//#include "../resource.h"
#include "player.h"
#include "front.h"
#include "sound.h"
#include "font.h"


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

	ChangeWindowMode(TRUE);
	SetMainWindowText("�����{�_�`�`The Pecten Maiden.  Ver.��");
	// �c�w���C�u�����̏�����
	if (DxLib_Init() == -1) return -1;

	// ����ʂ��g�p
	SetDrawScreen(DX_SCREEN_BACK);
	player reimutest;
	//shot reimushot;
	front front;
	double fps_ = 60;
	Count_ f=0;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		f++;
		//DrawBox(FIELD_MIN_X, FIELD_MIN_Y, FIELD_MAX_X, FIELD_MAX_Y, RGB(0, 255, 0), TRUE);
		front.draw();
		reimutest.updata();
		
		DrawFormatStringToHandle(540, 460, RGB(255, 255, 255),font_fps,"%02.1f fps", fps_);
		fps_ = fps();
	}
	// �c�w���C�u�����̎g�p�I��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}