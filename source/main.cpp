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
		FpsTime[0] = GetNowCount();               //1周目の時間取得
	if (FpsTime_i == 29) {
		FpsTime[1] = GetNowCount();               //50周目の時間取得
		Fps = 1000.00f / ((FpsTime[1] - FpsTime[0]) / 29.00f);//測定した値からfpsを計算
		FpsTime_i = 0;//カウントを初期化
	}
	else
		FpsTime_i++;//現在何周目かカウント

	return Fps;
}

void mswindow() {
	//MessageBox(NULL,"ウィンドウモードを選んでください","東方須神伝",MB_
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	char rate = 2;
	BOOL FULLSCREEN = 1;
	ChangeWindowMode(FULLSCREEN);
	SetMainWindowText("東方須神伝～The Pecten Maiden.  Ver.β");
	// ＤＸライブラリの初期化
	if (DxLib_Init() == -1) return -1;
	SetWindowSizeExtendRate(rate, rate);
	// 裏画面を使用
	SetDrawScreen(DX_SCREEN_BACK);
	player reimutest;
	front front;
	Count_ f=0;
	soundload();
	fontload();
	//バージョン
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
	// ＤＸライブラリの使用終了
	DxLib_End();

	// ソフトの終了
	return 0;
}