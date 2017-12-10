#include "sound.h"
#include "DxLib.h"

void playbgm(Sound_ bgm) {
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}
void playse(Sound_ se) {
	PlaySoundMem(se, DX_PLAYTYPE_BACK);
}
Sound_ shotse;
Sound_ bgm1_1;
void soundload() {
	 shotse = LoadSoundMem("se/shot.ogg");
	 bgm1_1 = LoadSoundMem("bgm/02.ogg");
}