#ifndef IMAGELOADER_INCLUDED
#define IMAGELOADER_INCLUDED
#include "Variables.h"
int Menu, loadingScreen;
int upperbackgroundlvl1[10], lowerbackgroundlvl1[10];
int upperbackgroundlvl2[10], lowerbackgroundlvl2[10];
int upperbackgroundlvl3[10], lowerbackgroundlvl3[10];
int upperbackgroundlvl4[10], lowerbackgroundlvl4[10];
int aboutUs,score,gameover;
void imageLoader(){
	Menu = iLoadImage("images\\Menu.png");
	loadingScreen = iLoadImage("images\\LoadingScreen.png");
	for (int i = 0; i < 10; i++){
		upperbackgroundlvl1[i] = iLoadImage(upperbglvl1[i]);
		lowerbackgroundlvl1[i] = iLoadImage(lowerbglvl1[i]);
		upperbackgroundlvl2[i] = iLoadImage(upperbglvl2[i]);
		lowerbackgroundlvl2[i] = iLoadImage(lowerbglvl2[i]);
		upperbackgroundlvl3[i] = iLoadImage(upperbglvl3[i]);
		lowerbackgroundlvl3[i] = iLoadImage(lowerbglvl3[i]);
		upperbackgroundlvl4[i] = iLoadImage(upperbglvl4[i]);
		lowerbackgroundlvl4[i] = iLoadImage(lowerbglvl4[i]);
	}
	aboutUs = iLoadImage("images\\about us.png");
	score = iLoadImage("images\\Score\\score.bmp");
	gameover = iLoadImage("images\\gameover.png");
}
#endif