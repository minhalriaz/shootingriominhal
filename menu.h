#ifndef MENU_INCLUDED
#define MENU_INCLUDED
#include "Variables.h"
#include "score.h"
void resetGame();
class menuButton{
public:
	int x, y;
};
menuButton menu_buttons[5];
void menu(int mx, int my){
	for (int i = 0; i < 5; i++){
		if (mx >= menu_buttons[i].x&&mx <= menu_buttons[i].x + 250 && my >= menu_buttons[i].y&&my <= menu_buttons[i].y + 110){
			gameState = i;
		}
	}
	if (gameState == 0){
		pause = false;
		//backgroundMusic = true;
	}
	else if (gameState == 2){
		highScores();
	}
}

#endif