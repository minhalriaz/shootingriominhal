#ifndef MUSIC_INCLUDED
#define MUSIC_INCLUDED
#include "Variables.h"
void playMusic(bool music){
	if (!mute){
		if (music){
			if (gameState == -1 || gameState == 1 || gameState == 2 || gameState == 3){
				PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else if (gameState == 0){
				if (firing){
					PlaySound("music\\Gunshot.wav", NULL, SND_ASYNC);
				}
				else if (playerMellee){
					PlaySound("music\\Knife.wav", NULL, SND_ASYNC);
				}
				else if (gameOver){
					PlaySound("music\\gameover.wav", NULL, SND_ASYNC);
				}
				else if (level > 1 && level <=4){
					PlaySound("music\\levelup.wav", NULL, SND_ASYNC);
				}
			}
		}
		else PlaySound(0, 0, 0);
	}
	else PlaySound(0, 0, 0);
}


#endif