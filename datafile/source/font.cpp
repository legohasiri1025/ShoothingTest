#include "DxLib.h"
#include "font.h"
int font_fps;
int font_front;

void fontload() {
	font_fps = CreateFontToHandle("���C���I", 10, 2, DX_FONTTYPE_ANTIALIASING_EDGE);
	font_front = CreateFontToHandle("���C���I", 18, 2,DX_FONTTYPE_ANTIALIASING_EDGE);
}