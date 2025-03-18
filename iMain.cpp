#include "iGraphics.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include "imageLoader.h"
#include "Variables.h"
#include "score.h"
#include "music.h"
#include "menu.h"

using namespace std;

void resetGame();

class background {
public:
	int x, y;
};

class bomb {
public:
	int x, y;
	bool bomb_visible;
};

class enemyMonster {
public:
	int monster_x, monster_y, monster_index;
	bool monster_visible;
};
void backButton() {
	gameState = -1; // Assuming 0 is the main menu state
}


background upperbg_lvl1[10];
background lowerbg_lvl1[10];
background upperbg_lvl4[10];
background lowerbg_lvl4[10];

enemyMonster monsters[MONSTERNUMBER];
bomb level1_bomb[BOMBNUMBER];

void menuBar() {
	iShowImage(0, 0, WIDTH, HEIGHT, Menu);
	for (int i = 0; i < 5; i++) {
		iShowBMP2(menu_buttons[i].x, menu_buttons[i].y, menubuttons[i], 0);
	}
}

void lifeBar() {
	if (lifebarVisible) {
		iShowBMP2(10, 740, life[life_index], 0);
	}
}

void bossLifeBar() {
	if (bossVisible) {
		iShowBMP2(WIDTH - 350, 700, bossLife[bossLifeIndex], 0);
	}
}

void gamePause() {
	iShowBMP2((WIDTH / 2) - 140, (HEIGHT / 2) - 140, "images\\pausePlay.bmp", 0);
}

void Player1Movement() {
	if (player1Visible) {
		if (jumping) {
			if (jumpup) {
				iShowBMP2(player1X, player1Y + playerJump, jump[0], 0);
			}
			else {
				iShowBMP2(player1X, player1Y + playerJump, jump[1], 0);
			}
		}
		else {
			if (standing) {
				iShowBMP2(player1X, player1Y, stand[stand_index], 0);
			}
			if (runningForward) {
				iShowBMP2(player1X, player1Y, run[run_index], 0);
			}
		}
		if (firing && front) {
			iShowBMP2(fireX, fireY, fire[0], 0);
		}
		if (firing && back) {
			iShowBMP2(fireX, fireY, fire[1], 0);
		}
	}
}

void bossMovement() {
	if (bossLevel) {
		if (bossVisible) {
			if (bossRunForward) {
				iShowBMP2(bossX, bossY, boss_run[bossRunIndex], 0);
			}
			if (bossfiring && bossRunForward) {
				iShowBMP2(bossFireX, bossFireY, fire[1], 0);
			}
		}
	}
}

void monsterMovement() {
	for (int i = 0; i < MONSTERNUMBER; i++) {
		if (monsters[i].monster_visible) {
			iShowBMP2(monsters[i].monster_x, monsters[i].monster_y, enemy2_lvl1[monsters[i].monster_index], 0);
		}
	}
}

void bombRender() {
	for (int i = 0; i < BOMBNUMBER; i++) {
		if (level1_bomb[i].bomb_visible) {
			iShowBMP2(level1_bomb[i].x, level1_bomb[i].y, bomb_level1[0], 0);
		}
	}
}
int bg;
void backGroundRender_level1() {
	iShowImage(0, 0, WIDTH, HEIGHT, bg);
	for (int i = 0; i < 10; i++) {

		iShowImage(lowerbg_lvl1[i].x, lowerbg_lvl1[i].y, 152, 150, lowerbackgroundlvl1[i]);
	}
}

void backgroundRender_level4() {
	for (int i = 0; i < 10; i++) {
		iShowImage(upperbg_lvl4[i].x, upperbg_lvl4[i].y, 152, HEIGHT - 150, upperbackgroundlvl4[i]);
		iShowImage(lowerbg_lvl4[i].x, lowerbg_lvl4[i].y, 152, 150, lowerbackgroundlvl4[i]);
	}
}

void level1EndRender() {
	if (lvl1end_keyVisible) {
		iShowBMP2(700, 150, level1_End[1], 0);
	}
	iShowBMP2(WIDTH - 300, 150, level1_End[0], 0);
	if (player1X >= WIDTH - 300 && (lvl1end_keyVisible == false)) {
		level = 4;
		playMusic(true);
		lifebarVisible = true;
		life_index = 0;
		player1Visible = true; // Ensure player is visible in Level 4
		bossLevel = true;
		bossVisible = true;
		player1X = 0;
		bossLevelTime = 10;
	}
}
int bg1;
void level4EndRender() {
	if (bossLifeIndex >= 7) { // Show treasure when boss health is zero
		iShowBMP2(WIDTH - 300, 100, "images\\Level 4\\LevelEnd\\tressure.bmp", 0);
		iShowImage(270, 160, WIDTH /2, HEIGHT/2 , bg1);
		completeGame = true; // End the game when the boss dies
	}
	if (player1Visible) {
		if (player1X >= WIDTH - 300) {
			completeGame = true;
			gameState = -2;
		}
	}
}

void collisionCheck() {
	if (!pause) {
		if (level == 1) {
			for (int i = 0; i < MONSTERNUMBER; i++) {
				if (monsters[i].monster_visible && player1Visible) {
					if ((player1X + 115 >= monsters[i].monster_x && player1X <= monsters[i].monster_x + 100) && (player1Y + playerJump >= monsters[i].monster_y && player1Y + playerJump <= monsters[i].monster_y + 100)) {
						life_index += 1;
						if (life_index >= 5) {
							player1Visible = false;
							life_index = 5;
							lifebarVisible = false;
							gameOver = true;
							playMusic(true);
							pause = true;
							gameState = -2;
							highscore(killScore);
						}
					}
				}
			}
			for (int i = 0; i < BOMBNUMBER; i++) {
				if (level1_bomb[i].bomb_visible && player1Visible) {
					if ((player1X + 115 >= level1_bomb[i].x && player1X <= level1_bomb[i].x + 75) && (player1Y + playerJump >= level1_bomb[i].y && player1Y + playerJump <= level1_bomb[i].y + 61)) {
						life_index += 1;
						level1_bomb[i].bomb_visible = false;
						if (life_index >= 5) {
							player1Visible = false;
							life_index = 5;
							lifebarVisible = false;
							gameOver = true;
							playMusic(true);
							pause = true;
							gameState = -2;
							highscore(killScore);
						}
					}
				}
			}
		}
		else if (level == 4 && bossLevel) {
			if (player1Visible) {
				for (int i = 0; i < BOMBNUMBER; i++) {
					if (level1_bomb[i].bomb_visible) {
						if ((player1X + 115 >= level1_bomb[i].x && player1X <= level1_bomb[i].x + 75) && (player1Y + playerJump >= level1_bomb[i].y && player1Y + playerJump <= level1_bomb[i].y + 61)) {
							life_index += 1;
							level1_bomb[i].bomb_visible = false;
							if (life_index >= 5) {
								life_index = 0;
								player1Visible = false;
								gameOver = true;
								playMusic(true);
								pause = true;
								gameState = -2;
								highscore(killScore);
							}
						}
					}
				}
			}
		}
	}
}

void bossCollisionCheck() {
	if (!pause) {
		if (level == 4 && bossLevel) {
			if (player1Visible && bossVisible && bossfiring) {
				if ((player1X <= bossFireX + 27 && player1X + 115 >= bossFireX) && (player1Y + playerJump <= bossFireY + 10 && player1Y + playerJump + 130 >= bossFireY)) {
					if (player1Visible && bossVisible) life_index += 1;
					bossfiring = false;
					random = 0;
					bossFireX = bossX + 10000000000000000000;
					if (life_index >= 5) {
						life_index = 0;
						player1Visible = false;
						gameOver = true;
						playMusic(true);
						pause = true;
						gameState = -2;
						highscore(killScore);
					}
				}
			}
		}
	}
}

void fireAndMelleeCollisionCheck() {
	if (!pause) {
		if (firing) {
			if (level == 1) {
				for (int i = 0; i < MONSTERNUMBER; i++) {
					if (monsters[i].monster_visible) {
						if ((fireX + 27 >= monsters[i].monster_x && fireX <= monsters[i].monster_x + 103) && (fireY <= monsters[i].monster_y + 100 && fireY + 19 >= monsters[i].monster_y)) {
							monsters[i].monster_visible = false;
							firing = false;
							fireX = player1X + 10000000000000000000;
							enemyKilled++;
							killScore += 5;
						}
					}
				}
			}
			else if (level == 4 && bossLevel) {
				if (player1Visible && bossVisible) {
					if ((fireX + 27 >= bossX && fireX <= bossX + 121) && (fireY <= bossY + 157 && fireY + 19 >= bossY)) {
						if (bossLifeIndex < 7) { // Ensure boss health does not reset
							bossLifeIndex += 1;
							firing = false;
							fireX = player1X + 10000000000000000000;
							killScore += 5;
						}
						if (bossLifeIndex >= 7) { // Boss dies after 7 hits
							bossVisible = false;
							bossLevel = false;
							highscore(killScore);
						}
					}
				}
			}
		}
	}
}

void iDraw() {
	iClear();
	if (gameState == -1) {
		menuBar();
	}
	if (gameState == 0 && level == 1) {
		backGroundRender_level1();
		scoreCounter();
		lifeBar();
		monsterMovement();
		bombRender();
		Player1Movement();
		if (pause) gamePause();
		iShowImage(WIDTH / 2 - (155 / 2), HEIGHT - 69, 155, 69, iLoadImage("images\\Level 1.png"));
	}
	else if (gameState == 0 && level == 4) {
		if (bossLevel) {
			backgroundRender_level4();
			scoreCounter();
			lifeBar();
			bossLifeBar();
			Player1Movement();
			bossMovement();
			bombRender();
			if (pause) gamePause();
			iShowImage(WIDTH / 2 - (155 / 2), HEIGHT - 69, 155, 69, iLoadImage("images\\Level 2.png"));
		}
		else {
			backgroundRender_level4();
			level4EndRender();
			Player1Movement();
		}
	}
	else if (gameState == 1) {
		iShowImage(0, 0, WIDTH, HEIGHT, iLoadImage("images\\help.png"));
	}
	else if (gameState == 2) {
		iShowImage(0, 0, WIDTH, HEIGHT, score);
		showScore();
	}
	else if (gameState == 3) {
		iShowImage(0, 0, WIDTH, HEIGHT, aboutUs);
	}
	else if (gameState == 4) {
		exit(0);
	}
	else if (completeGame) {
		iShowImage(0, 0, WIDTH, HEIGHT, iLoadImage("images\\CONGO.png"));
		resetGame();
	}
	else if (gameOver) {
		iShowImage(0, 0, WIDTH, HEIGHT, gameover);
		resetGame();
	}
}

void change() {
	if (!pause) {
		if (level == 1) {
			if (standing) {
				stand_index++;
				if (stand_index > 3) stand_index = 0;
			}
			if (jumping) {
				if (jumpup) {
					playerJump += 5;
					if (playerJump >= JUMPLIMIT) {
						jumpup = false;
					}
				}
				else {
					playerJump -= 5;
					if (playerJump < 0) {
						playerJump = 0;
						jumping = false;
						standing = true; // Reset to standing after landing
					}
				}
			}
			if (level1Characters) {
				for (int i = 0; i < BOMBNUMBER; i++) {
					level1_bomb[i].x -= 10;
					if (level1_bomb[i].x < 0) level1_bomb[i].x = WIDTH + rand() % 40000;
					if (level1_bomb[i].bomb_visible == false) {
						level1_bomb[i].bomb_visible = true;
						level1_bomb[i].x = WIDTH + rand() % 40000;
					}
				}
				for (int i = 0; i < MONSTERNUMBER; i++) {
					if (monsters[i].monster_visible) {
						monsters[i].monster_x -= 10;
						monsters[i].monster_index++;
						if (player1Visible) {
							if (abs(monsters[i].monster_x - (player1X + 50)) <= 5) {
								monsters[i].monster_visible = false;
							}
						}
						if (monsters[i].monster_x <= 0) monsters[i].monster_x = WIDTH + rand() % 80000 + rand() % 6;
						if (monsters[i].monster_index >= 5) monsters[i].monster_index = 0;
					}
					if (monsters[i].monster_visible == false) {
						monsters[i].monster_x = WIDTH + rand() % 100000 + rand() % 8;
						monsters[i].monster_y = 150;
						monsters[i].monster_visible = true;
					}
				}
			}
			// Transition to Level 4 when score reaches 50
			if (killScore >= 30) {
				level = 4;
				playMusic(true);
				lifebarVisible = true;
				life_index = 0;
				player1Visible = true; // Ensure player is visible in Level 4
				bossLevel = true;
				bossVisible = true;
				player1X = 0;
				bossLevelTime = 10;
			}
		}
		else if (level == 4) {
			if (standing) {
				stand_index++;
				if (stand_index > 3) stand_index = 0;
			}
			if (jumping) {
				if (jumpup) {
					playerJump += 5;
					if (playerJump >= JUMPLIMIT) {
						jumpup = false;
					}
				}
				else {
					playerJump -= 5;
					if (playerJump < 0) {
						playerJump = 0;
						jumping = false;
						standing = true; // Reset to standing after landing
					}
				}
			}
			if (bossVisible && bossLevel) {
				for (int i = 0; i < BOMBNUMBER; i++) {
					level1_bomb[i].y = 120;
					level1_bomb[i].x -= 10;
					if (level1_bomb[i].x < 0) level1_bomb[i].x = WIDTH + rand() % 20000;
					if (level1_bomb[i].bomb_visible == false) {
						level1_bomb[i].bomb_visible = true;
						level1_bomb[i].x = WIDTH + rand() % 30000;
					}
				}
			}
		}
	}
}

void bossMovements() {
	if (!pause) {
		if (bossLevel && level == 4) {
			if (bossVisible) {
				if (bossRunForward) {
					bossX -= (rand() % 3 + 1);
				}
				if (player1Visible) {
					if (player1X > bossX) {
						bossRunForward = true;
					}
					else {
						bossRunForward = true;
					}
				}
				bossRunIndex++;
				if (bossRunIndex >= 5) bossRunIndex = 0;
				if (bossX >= WIDTH - 115) bossX = WIDTH - 115;
				if (bossX <= WIDTH / 2) bossX = WIDTH / 2;
				if (bossfiring == false) {
					random++;
					if (random >= (rand() % 70 + 1)) {
						bossfiring = true;
						bossFireX = bossX;
						bossFireY = bossY + 100;
					}
				}
				if (bossfiring && bossRunForward) {
					for (int i = 0; i < 35; i++) {
						bossFireX--;
						if (bossFireX < 0) {
							bossfiring = false;
							random = 0;
							bossFireX = bossX + 10000000000000000000;
						}
					}
				}
			}
		}
	}
}

void fire_bullet() {
	if (!pause) {
		if (firing && front) {
			for (int i = 0; i < 152; i++) {
				fireX++;
				if (fireX > WIDTH) {
					firing = false;
					if (level == 1) fireX = player1X + 10000000000000000000;
					else if (level == 4) {
						if (player1Visible) fireX = player1X + 10000000000000000000;
					}
				}
			}
		}
	}
}

void ending_Level_logic() {
	if (level == 1) {
		if (killScore >= 50) { // Transition to Level 4 when score reaches 50
			level = 4;
			playMusic(true);
			lifebarVisible = true;
			life_index = 0;
			player1Visible = true; // Ensure player is visible in Level 4
			bossLevel = true;
			bossVisible = true;
			player1X = 0;
			bossLevelTime = 10;
		}
	}
}

void setBomb_level1() {
	for (int i = 0; i < BOMBNUMBER; i++) {
		level1_bomb[i].x = WIDTH + rand() % 30000;
		level1_bomb[i].y = 150;
		level1_bomb[i].bomb_visible = true;
	}
}

void setBackgroundVariables_level1() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		upperbg_lvl1[i].y = 150;
		lowerbg_lvl1[i].y = 0;
		upperbg_lvl1[i].x = sum;
		lowerbg_lvl1[i].x = sum;
		sum += 152;
	}
}

void setBackgroundVariables_level4() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		upperbg_lvl4[i].y = 150;
		lowerbg_lvl4[i].y = 0;
		upperbg_lvl4[i].x = sum;
		lowerbg_lvl4[i].x = sum;
		sum += 152;
	}
}

void setEnemyMonsterVariables_level1() {
	for (int i = 0; i < MONSTERNUMBER; i++) {
		monsters[i].monster_x = WIDTH + rand() % 100000;
		monsters[i].monster_y = 150;
		monsters[i].monster_index = rand() % 6;
		monsters[i].monster_visible = true;
	}
}

void setMenu() {
	int sum = 50;
	for (int i = 4; i >= 0; i--) {
		menu_buttons[i].x = 1000;
		menu_buttons[i].y = sum;
		sum += 120;
	}
}

void resetGame() {
	setEnemyMonsterVariables_level1();
	setBomb_level1();
	setBackgroundVariables_level1();
	setBackgroundVariables_level4();
	if (level1Characters == false) {
		level1Characters = true;
	}
	if (player1Visible == false) {
		player1X = 0;
		player1Y = 150;
		player1Visible = true;
	}
	level = 1;
	killScore = 0;
	enemyKilled = 0;
	life_index = 0;
	lifebarVisible = true;
	bossRunForward = true; bossfiring = false;
	bossVisible = true; counts = 0; bossRunIndex = 0; bossLifeIndex = 0; bossX = WIDTH - 115; bossY = 100;
	random = 0;
}

void iMouseMove(int mx, int my) {}

void iPassiveMouseMove(int mx, int my) {}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		menu(mx, my);
	}
}

void iKeyboard(unsigned char key) {
	if (key == 'b' || key == 'B') {
		backButton();
	}
	if (key == 'x') {
		exit(0);
	}
	if (key == '\b') {
		if (gameState == 3 || gameState == 2 || gameState == 1) gameState = -1;
		else if (gameOver) {
			gameOver = false;
			gameState = -1;
		}
		else if (completeGame) {
			completeGame = false; gameState = -1;
		}
	}
	if (key == 'A' || key == 'a') {
		if (!pause) {
			if (!firing) {
				firing = true;
				playMusic(true);
				if (level == 1) {
					fireX = player1X;
					if (jumping) fireY = player1Y + playerJump + 100;
					else fireY = player1Y + 100;
				}
				else if (level == 4) {
					if (bossLevel) {
						if (player1Visible) {
							fireX = player1X;
							if (jumping) fireY = player1Y + playerJump + 100;
							else fireY = player1Y + 100;
						}
					}
				}
			}
		}
	}
	if (key == 'm' || key == 'M') {
		if (!mute) {
			mute = true;
			playMusic(false);
		}
		else {
			mute = false;
			playMusic(true);
		}
	}
	if (key == 'p' || key == 'P') {
		if (!pause) {
			pause = true;
		}
		else {
			pause = false;
		}
	}
}

void iSpecialKeyboard(unsigned char key) {
	if (key == GLUT_KEY_RIGHT) {
		if (!pause) {
			running = true;
			runningForward = true;
			if (jumping) runningForward = false;
			if (level == 1) {
				player1X += 5;
				if (player1X >= WIDTH) player1X = -10;
			}
			else if (level == 4) {
				if (bossLevel) {
					if (player1Visible) {
						player1X += 5;
						if (player1X >= WIDTH) player1X = -10;
					}
				}
			}
			if (runningForward) run_index++;
			if (run_index >= 5) run_index = 0;
			standing = false;
			front = true; back = false;
		}
	}
	if (key == GLUT_KEY_LEFT) {
		if (!pause) {
			running = true;
			runningForward = false;
			if (jumping) runningForward = false;
			if (level == 1) {
				player1X -= 5;
				if (player1X <= 0) player1X = 0;
			}
			else if (level == 4) {
				if (bossLevel) {
					if (player1Visible) {
						player1X -= 5;
						if (player1X <= 0) player1X = 0;
					}
				}
			}
			if (runningForward) run_index++;
			if (run_index >= 5) run_index = 0;
			standing = false;
			front = false; back = true;
		}
	}
	if (key == GLUT_KEY_UP) {
		if (!pause) {
			if (!jumping) {
				jumping = jumpup = true;
				runningForward = standing = false;
			}
		}
	}
}

int main() {
	setMenu();
	resetGame();
	iSetTimer(1000, collisionCheck);
	iSetTimer(25, fireAndMelleeCollisionCheck);
	iSetTimer(165, bossCollisionCheck);
	endingLevel = iSetTimer(2, ending_Level_logic);
	iSetTimer(50, change);
	iSetTimer(10, fire_bullet);
	iSetTimer(40, bossMovements);
	iInitialize(WIDTH, HEIGHT, "Shooting Rio");
	bg = iLoadImage("images\\back.bmp");
	bg1 = iLoadImage("images\\CONGO.png");
	imageLoader();
	playMusic(true);
	iStart();
	return 0;
}