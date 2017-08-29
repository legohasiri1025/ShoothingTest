#include "DxLib.h"
#include "define.h"
#include "func.h"
#include "bullet.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	SetMainWindowText("ShootingTest");
	// ＤＸライブラリの初期化
	if (DxLib_Init() == -1) return -1;

	// 裏画面を使用
	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){

		// 画面の更新
		ScreenFlip();
	}
	// ＤＸライブラリの使用終了
	DxLib_End();

	// ソフトの終了
	return 0;
}