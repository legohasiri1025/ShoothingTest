#include "sound.h"
#include "DxLib.h"

void playbgm(Sound_ bgm) {
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
}
void playse(Sound_ se) {
	PlaySoundMem(se, DX_PLAYTYPE_BACK);
}

