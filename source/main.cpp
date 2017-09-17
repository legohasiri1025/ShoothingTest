#include "DxLib.h"
#include "player.h"
#include "front.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	SetMainWindowText("東方須神伝～The Pecten Maiden.  Ver.β");
	// ＤＸライブラリの初期化
	if (DxLib_Init() == -1) return -1;

	// 裏画面を使用
	SetDrawScreen(DX_SCREEN_BACK);
	player reimutest;
	shot reimushot;
	front front;
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		//DrawBox(FIELD_MIN_X, FIELD_MIN_Y, FIELD_MAX_X, FIELD_MAX_Y, RGB(0, 255, 0), TRUE);

		front.draw();
		reimutest.move();
		reimutest.draw();
		reimushot.mainshot1();
		reimushot.mainshot2();
	}
	// ＤＸライブラリの使用終了
	DxLib_End();

	// ソフトの終了
	return 0;
}