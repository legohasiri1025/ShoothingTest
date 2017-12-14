#include "sound.h"
#include "DxLib.h"

void playbgm(Sound_ bgm) {
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}
void playse(Sound_ se) {
	PlaySoundMem(se, DX_PLAYTYPE_BACK);
}
Sound_ shotse;


Sound_ bgm[7][2];
Sound_ title;
Sound_ ending;
Sound_ staffroll;
Sound_ gameover;
void soundload() {
	 shotse = LoadSoundMem("datafile/se/shot.ogg");
	 bgm[0][0] = LoadSoundMem("datafile/bgm/02.ogg");
}