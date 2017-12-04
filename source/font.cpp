#include "DxLib.h"
#include "font.h"
int font_fps;
int font_front;

void fontload() {
	font_fps = CreateFontToHandle("メイリオ", 10, 2, DX_FONTTYPE_ANTIALIASING_EDGE);
	font_front = CreateFontToHandle("メイリオ", 18, 2,DX_FONTTYPE_ANTIALIASING_EDGE);
}