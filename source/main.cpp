#include "DxLib.h"
#include "player.h"
#include "front.h"
#include "sound.h"

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
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//DrawBox(FIELD_MIN_X, FIELD_MIN_Y, FIELD_MAX_X, FIELD_MAX_Y, RGB(0, 255, 0), TRUE);
		front.draw();
		reimutest.updata();
	}
	// �c�w���C�u�����̎g�p�I��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}