#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED
#define WIDTH 1520
#define HEIGHT 800
#define JUMPLIMIT 200
#define BIRDNUMBER 15
#define upperbgspeed 152
#define lowerbgspeed 152
#define MONSTERNUMBER 25
#define ZOMBIENUMBER 35
#define MONSTER_LEVEL2 25
#define ZOMBIE_LEVEL2 35
#define MONSTER_LEVEL3 25
#define ZOMBIE_LEVEL3 35
#define screencondition 1
#define groundcondition 1
#define BOMBNUMBER 12
#define BOXNUMBER 15
bool music = false, standing = false, standRev = false;
bool firing = false;
bool front = false, back = false;
int player1X = 0, player1Y = 150, playerJump = 0;
int player2X = 0, player2Y = 50;
int player3X = 0, player3Y = 120;//112 width and 177 height
int fireX = 0, fireY = 0;
int melleeX = 0, melleeY = 0;
int run_index = 0, stand_counter = 0, run_counter = 0;
char scores[10][1000];
char playernames[10][500];
int level = 1;
int stand_index = 0;
int gameState = -1;
int life_index = 0, monster_index = 0;
bool jumping = false, jumpup = false, runningForward = false, runningBackward = false, player1Visible = true, player2Visible = false, player3Visible = false;
bool playerMellee = false ;
bool running = false;
bool mute = false;
bool level1Characters = true, level2Characters = false, level3Characters = false, bossLevel = false;
bool lvl1end_keyVisible = false, lvl2end_keyVisible = false;
bool lifebarVisible = true;
bool pause = true;
int player1_mellee_index = 0, player2_mellee_index = 0, player3_mellee_index = 0;
int enemyKilled = 0;
int endingLevel;
int killScore = 0;
bool gameOver = false;
int charIndex = 0;
bool backgroundMusic = false;
bool completeGame = false;
bool bossRunForward = true, bossRunBackward = false, bossJumping = false, bossJumpUp = false, bossfiring = false;
bool bossVisible = false;
int bossLevelTime = 50;
int bossRunIndex = 0, bossStandIndex = 0, bossJump = 0, bossX = WIDTH - 115, bossY = 100, random = 0, bossFireX, bossFireY, bossLifeIndex = 0, counts = 1;
char run[6][60] = { "images\\Level 1\\Player 1\\Run\\run01.bmp",
"images\\Level 1\\Player 1\\Run\\run02.bmp",
"images\\Level 1\\Player 1\\Run\\run03.bmp",
"images\\Level 1\\Player 1\\Run\\run04.bmp",
"images\\Level 1\\Player 1\\Run\\run05.bmp",
"images\\Level 1\\Player 1\\Run\\run06.bmp" };
char run_level2[6][60] = {"images\\Level 2\\Player 2\\Run\\run01.bmp",
"images\\Level 2\\Player 2\\Run\\run02.bmp", 
"images\\Level 2\\Player 2\\Run\\run03.bmp", 
"images\\Level 2\\Player 2\\Run\\run04.bmp", 
"images\\Level 2\\Player 2\\Run\\run05.bmp", 
"images\\Level 2\\Player 2\\Run\\run06.bmp" };
char rev[6][60] = { "images\\Level 1\\Player 1\\Reverse\\run01.bmp",
"images\\Level 1\\Player 1\\Reverse\\run02.bmp",
"images\\Level 1\\Player 1\\Reverse\\run03.bmp",
"images\\Level 1\\Player 1\\Reverse\\run04.bmp",
"images\\Level 1\\Player 1\\Reverse\\run05.bmp",
"images\\Level 1\\Player 1\\Reverse\\run06.bmp" };
char rev_level2[6][60] = { "images\\Level 2\\Player 2\\Reverse\\run01.bmp",
"images\\Level 2\\Player 2\\Reverse\\run02.bmp",
"images\\Level 2\\Player 2\\Reverse\\run03.bmp",
"images\\Level 2\\Player 2\\Reverse\\run04.bmp",
"images\\Level 2\\Player 2\\Reverse\\run05.bmp",
"images\\Level 2\\Player 2\\Reverse\\run06.bmp" };
char rev_level3[6][60] = {"images\\Level 3\\Player\\Reverse\\run01.bmp",
"images\\Level 3\\Player\\Reverse\\run02.bmp", 
"images\\Level 3\\Player\\Reverse\\run03.bmp", 
"images\\Level 3\\Player\\Reverse\\run04.bmp", 
"images\\Level 3\\Player\\Reverse\\run05.bmp", 
"images\\Level 3\\Player\\Reverse\\run06.bmp" };
char run_level3[6][60] = {"images\\Level 3\\Player\\Run\\run01.bmp",
"images\\Level 3\\Player\\Run\\run02.bmp",
"images\\Level 3\\Player\\Run\\run03.bmp",
"images\\Level 3\\Player\\Run\\run04.bmp",
"images\\Level 3\\Player\\Run\\run05.bmp",
"images\\Level 3\\Player\\Run\\run06.bmp" };
char stand[6][50] = { "images\\Level 1\\Player 1\\Stand\\stand01.bmp",
"images\\Level 1\\Player 1\\Stand\\stand02.bmp",
"images\\Level 1\\Player 1\\Stand\\stand03.bmp",
"images\\Level 1\\Player 1\\Stand\\stand04.bmp" };
char stand_level2[4][60] = {"images\\Level 2\\Player 2\\stand\\stand01.bmp",
"images\\Level 2\\Player 2\\stand\\stand02.bmp", 
"images\\Level 2\\Player 2\\stand\\stand03.bmp", 
"images\\Level 2\\Player 2\\stand\\stand04.bmp" };
char stand_level3[4][60] = {"images\\Level 3\\Player\\stand\\stand01.bmp",
"images\\Level 3\\Player\\stand\\stand02.bmp", 
"images\\Level 3\\Player\\stand\\stand03.bmp",
"images\\Level 3\\Player\\stand\\stand04.bmp" };
char standingRev[6][50] = { "images\\Level 1\\Player 1\\StandRev\\stand01.bmp",
"images\\Level 1\\Player 1\\StandRev\\stand02.bmp",
"images\\Level 1\\Player 1\\StandRev\\stand03.bmp",
"images\\Level 1\\Player 1\\StandRev\\stand04.bmp" };
char standrev_level2[4][60] = {"images\\Level 2\\Player 2\\stand rev\\stand01.bmp",
"images\\Level 2\\Player 2\\stand rev\\stand02.bmp", 
"images\\Level 2\\Player 2\\stand rev\\stand03.bmp", 
"images\\Level 2\\Player 2\\stand rev\\stand04.bmp" };
char standrev_level3[4][60] = {"images\\Level 3\\Player\\standRev\\stand01.bmp",
"images\\Level 3\\Player\\standRev\\stand02.bmp", 
"images\\Level 3\\Player\\standRev\\stand03.bmp", 
"images\\Level 3\\Player\\standRev\\stand04.bmp" };
char life[6][50] = {"images\\Level 1\\Player 1\\LifeBar\\life01.bmp",
"images\\Level 1\\Player 1\\LifeBar\\life02.bmp", 
"images\\Level 1\\Player 1\\LifeBar\\life03.bmp", 
"images\\Level 1\\Player 1\\LifeBar\\life04.bmp", 
"images\\Level 1\\Player 1\\LifeBar\\life05.bmp",
"images\\Level 1\\Player 1\\LifeBar\\life06.bmp" };
char bossLife[8][60] = {"images\\Level 4\\Boss\\lifeBar\\bosslifebar01.bmp",
"images\\Level 4\\Boss\\lifeBar\\bosslifebar02.bmp", 
"images\\Level 4\\Boss\\lifeBar\\bosslifebar03.bmp", 
"images\\Level 4\\Boss\\lifeBar\\bosslifebar04.bmp", 
"images\\Level 4\\Boss\\lifeBar\\bosslifebar05.bmp", 
"images\\Level 4\\Boss\\lifeBar\\bosslifebar06.bmp",
"images\\Level 4\\Boss\\lifeBar\\bosslifebar07.bmp",
"images\\Level 4\\Boss\\lifeBar\\bosslifebar08.bmp" };
char fire[2][60] = { "images\\Level 1\\Player 1\\Fire\\fire_bullet.bmp" ,
"images\\Level 1\\Player 1\\Fire\\fire_bullet_reverse.bmp" };
char jump[2][40] = { "images\\Level 1\\Player 1\\Jump\\jump1.bmp", "images\\Level 1\\Player 1\\Jump\\jump2.bmp" };
char jump_level2[2][40] = {"images\\Level 2\\Player 2\\Jump\\jump01.bmp",
"images\\Level 2\\Player 2\\Jump\\jump02.bmp"};
char jump_level3[2][40] = {"images\\Level 3\\Player\\jump\\jump01.bmp",
"images\\Level 3\\Player\\jump\\jump02.bmp" };
char player1_mellee[4][50] = {"images\\Level 1\\Player 1\\melle\\mellee01.bmp",
"images\\Level 1\\Player 1\\melle\\mellee02.bmp", 
"images\\Level 1\\Player 1\\melle\\mellee03.bmp", 
"images\\Level 1\\Player 1\\melle\\mellee04.bmp" };
char player2_mellee[4][60] = {"images\\Level 2\\Player 2\\mellee\\mellee01.bmp",
"images\\Level 2\\Player 2\\mellee\\mellee02.bmp", 
"images\\Level 2\\Player 2\\mellee\\mellee03.bmp", 
"images\\Level 2\\Player 2\\mellee\\mellee04.bmp" };
char player3_mellee[4][60] = {"images\\Level 3\\Player\\mellee\\mellee01.bmp",
"images\\Level 3\\Player\\mellee\\mellee02.bmp", 
"images\\Level 3\\Player\\mellee\\mellee03.bmp", 
"images\\Level 3\\Player\\mellee\\mellee04.bmp"};
char bomb_level1[1][50] = {"images\\Level 1\\Objects\\bomb.bmp"};
char box_level2[1][60] = {"images\\Level 2\\Objects\\box.bmp"};
char level1_End[2][50] = {"images\\Level 1\\LevelEnd\\Truck.bmp",
"images\\Level 1\\LevelEnd\\key.bmp"};
char level2_End[2][60] = {"images\\Level 2\\LevelEnd\\helicopter.bmp",
"images\\Level 2\\LevelEnd\\crown1.bmp"};
char level3_End[1][50] = {"images\\Level 3\\levelEnd\\car.bmp"};
char enemy1_lvl1[10][60] = { "images\\Level 1\\Enemy 1\\flying01.bmp",
"images\\Level 1\\Enemy 1\\flying02.bmp",
"images\\Level 1\\Enemy 1\\flying03.bmp",
"images\\Level 1\\Enemy 1\\flying04.bmp",
"images\\Level 1\\Enemy 1\\flying05.bmp",
"images\\Level 1\\Enemy 1\\flying06.bmp",
"images\\Level 1\\Enemy 1\\flying07.bmp",
"images\\Level 1\\Enemy 1\\flying08.bmp",
"images\\Level 1\\Enemy 1\\flying09.bmp",
"images\\Level 1\\Enemy 1\\flying10.bmp" };
char enemy2_lvl1[6][60] = { "images\\Level 1\\Enemy2\\Run\\running1.bmp",
"images\\Level 1\\Enemy2\\Run\\running2.bmp",
"images\\Level 1\\Enemy2\\Run\\running3.bmp",
"images\\Level 1\\Enemy2\\Run\\running4.bmp",
"images\\Level 1\\Enemy2\\Run\\running5.bmp",
"images\\Level 1\\Enemy2\\Run\\running6.bmp", };
char enemy2_mellee[4][50] = {"images\\Level 1\\Enemy2\\mellee\\mellee01.bmp",
"images\\Level 1\\Enemy2\\mellee\\mellee02.bmp", 
"images\\Level 1\\Enemy2\\mellee\\mellee03.bmp", 
"images\\Level 1\\Enemy2\\mellee\\mellee04.bmp" };
char enemy3_lvl1[6][50] = {"images\\Level 1\\Enemy3\\Run\\run05.bmp", 
"images\\Level 1\\Enemy3\\Run\\run06.bmp",
"images\\Level 1\\Enemy3\\Run\\run07.bmp", 
"images\\Level 1\\Enemy3\\Run\\run08.bmp", 
"images\\Level 1\\Enemy3\\Run\\run09.bmp", 
"images\\Level 1\\Enemy3\\Run\\run10.bmp" };
char enemy3_idle[4][50] = {"images\\Level 1\\Enemy3\\idle\\idle01.bmp",
"images\\Level 1\\Enemy3\\idle\\idle02.bmp", 
"images\\Level 1\\Enemy3\\idle\\idle03.bmp", 
"images\\Level 1\\Enemy3\\idle\\idle04.bmp" };
char enemy3_mellee[6][50] = {"images\\Level 1\\Enemy3\\mellee\\mellee01.bmp",
"images\\Level 1\\Enemy3\\mellee\\mellee02.bmp", 
"images\\Level 1\\Enemy3\\mellee\\mellee03.bmp", 
"images\\Level 1\\Enemy3\\mellee\\mellee04.bmp", 
"images\\Level 1\\Enemy3\\mellee\\mellee05.bmp", 
"images\\Level 1\\Enemy3\\mellee\\mellee06.bmp" };
char enemy1_level2[6][60] = {"images\\Level 2\\Enemy 1\\run\\run01.bmp",
"images\\Level 2\\Enemy 1\\run\\run02.bmp", 
"images\\Level 2\\Enemy 1\\run\\run03.bmp", 
"images\\Level 2\\Enemy 1\\run\\run04.bmp", 
"images\\Level 2\\Enemy 1\\run\\run05.bmp", 
"images\\Level 2\\Enemy 1\\run\\run06.bmp" };
char enemy1_level2_mellee[4][60] = {"images\\Level 2\\Enemy 1\\mellee\\mellee01.bmp",
"images\\Level 2\\Enemy 1\\mellee\\mellee02.bmp", 
"images\\Level 2\\Enemy 1\\mellee\\mellee03.bmp", 
"images\\Level 2\\Enemy 1\\mellee\\mellee04.bmp" };
char enemy2_level2[5][60] = {"images\\Level 2\\Enemy 2\\run\\run01.bmp",
"images\\Level 2\\Enemy 2\\run\\run02.bmp",
"images\\Level 2\\Enemy 2\\run\\run03.bmp", 
"images\\Level 2\\Enemy 2\\run\\run04.bmp", 
"images\\Level 2\\Enemy 2\\run\\run05.bmp" };
char enemy2_level2_mellee[6][60] = {"images\\Level 2\\Enemy 2\\mellee\\mellee01.bmp",
"images\\Level 2\\Enemy 2\\mellee\\mellee02.bmp", 
"images\\Level 2\\Enemy 2\\mellee\\mellee03.bmp", 
"images\\Level 2\\Enemy 2\\mellee\\mellee04.bmp", 
"images\\Level 2\\Enemy 2\\mellee\\mellee05.bmp", 
"images\\Level 2\\Enemy 2\\mellee\\mellee06.bmp" };
char enemy2_level2_idle[4][60] = {"images\\Level 2\\Enemy 2\\idle\\idle01.bmp",
"images\\Level 2\\Enemy 2\\idle\\idle02.bmp", 
"images\\Level 2\\Enemy 2\\idle\\idle03.bmp", 
"images\\Level 2\\Enemy 2\\idle\\idle04.bmp" };
char enemy1_level3_run[6][60] = {"images\\Level 3\\Enemy 1\\run\\run01.bmp",
"images\\Level 3\\Enemy 1\\run\\run02.bmp", 
"images\\Level 3\\Enemy 1\\run\\run03.bmp", 
"images\\Level 3\\Enemy 1\\run\\run04.bmp", 
"images\\Level 3\\Enemy 1\\run\\run05.bmp", 
"images\\Level 3\\Enemy 1\\run\\run06.bmp" };
char enemy1_level3_mellee[6][60] = {"images\\Level 3\\Enemy 1\\attack\\mellee01.bmp",
"images\\Level 3\\Enemy 1\\attack\\mellee02.bmp", 
"images\\Level 3\\Enemy 1\\attack\\mellee03.bmp", 
"images\\Level 3\\Enemy 1\\attack\\mellee04.bmp", 
"images\\Level 3\\Enemy 1\\attack\\mellee05.bmp", 
"images\\Level 3\\Enemy 1\\attack\\mellee06.bmp" };
char enemy2_level3_mellee[6][60] = {"images\\Level 3\\Enemy 2\\attack\\mellee01.bmp",
"images\\Level 3\\Enemy 2\\attack\\mellee02.bmp", 
"images\\Level 3\\Enemy 2\\attack\\mellee03.bmp", 
"images\\Level 3\\Enemy 2\\attack\\mellee04.bmp", 
"images\\Level 3\\Enemy 2\\attack\\mellee05.bmp", 
"images\\Level 3\\Enemy 2\\attack\\mellee06.bmp" };
char enemy2_level3_run[6][60] = {"images\\Level 3\\Enemy 2\\run\\run01.bmp",
"images\\Level 3\\Enemy 2\\run\\run02.bmp", 
"images\\Level 3\\Enemy 2\\run\\run03.bmp", 
"images\\Level 3\\Enemy 2\\run\\run04.bmp", 
"images\\Level 3\\Enemy 2\\run\\run05.bmp" };
char enemy2_level3_idle[4][60] = {"images\\Level 3\\Enemy 2\\idle\\idle01.bmp",
"images\\Level 3\\Enemy 2\\idle\\idle02.bmp", 
"images\\Level 3\\Enemy 2\\idle\\idle03.bmp", 
"images\\Level 3\\Enemy 2\\idle\\idle04.bmp" };
char boss_run[6][60] = {"images\\Level 4\\Boss\\run\\run01.bmp",
"images\\Level 4\\Boss\\run\\run02.bmp", 
"images\\Level 4\\Boss\\run\\run03.bmp", 
"images\\Level 4\\Boss\\run\\run04.bmp", 
"images\\Level 4\\Boss\\run\\run05.bmp", 
"images\\Level 4\\Boss\\run\\run06.bmp" };
char boss_jump[2][60] = { "images\\Level 4\\Boss\\jump\\jump01.bmp",
"images\\Level 4\\Boss\\jump\\jump02.bmp" };
char boss_stand[4][60] = { "images\\Level 4\\Boss\\stand\\stand01.bmp",
"images\\Level 4\\Boss\\stand\\stand02.bmp",
"images\\Level 4\\Boss\\stand\\stand03.bmp",
"images\\Level 4\\Boss\\stand\\stand04.bmp" };
char boss_reverse[6][60] = {"images\\Level 4\\Boss\\reverse\\run01.bmp",
"images\\Level 4\\Boss\\reverse\\run02.bmp", 
"images\\Level 4\\Boss\\reverse\\run03.bmp", 
"images\\Level 4\\Boss\\reverse\\run04.bmp", 
"images\\Level 4\\Boss\\reverse\\run05.bmp", 
"images\\Level 4\\Boss\\reverse\\run06.bmp"};
char upperbglvl1[10][40] = { "images\\Level 1\\Background\\upperbg01.bmp",
"images\\Level 1\\Background\\upperbg02.bmp",
"images\\Level 1\\Background\\upperbg03.bmp",
"images\\Level 1\\Background\\upperbg04.bmp",
"images\\Level 1\\Background\\upperbg05.bmp",
"images\\Level 1\\Background\\upperbg06.bmp",
"images\\Level 1\\Background\\upperbg07.bmp",
"images\\Level 1\\Background\\upperbg08.bmp",
"images\\Level 1\\Background\\upperbg09.bmp",
"images\\Level 1\\Background\\upperbg10.bmp" };
char lowerbglvl1[10][40] = { "images\\Level 1\\Background\\lowerbg01.bmp",
"images\\Level 1\\Background\\lowerbg02.bmp",
"images\\Level 1\\Background\\lowerbg03.bmp",
"images\\Level 1\\Background\\lowerbg04.bmp",
"images\\Level 1\\Background\\lowerbg05.bmp",
"images\\Level 1\\Background\\lowerbg06.bmp",
"images\\Level 1\\Background\\lowerbg07.bmp",
"images\\Level 1\\Background\\lowerbg08.bmp",
"images\\Level 1\\Background\\lowerbg09.bmp",
"images\\Level 1\\Background\\lowerbg10.bmp" };
char upperbglvl2[10][50] = {"images\\Level 2\\Background\\upperbg01.bmp",
"images\\Level 2\\Background\\upperbg02.bmp", 
"images\\Level 2\\Background\\upperbg03.bmp", 
"images\\Level 2\\Background\\upperbg04.bmp", 
"images\\Level 2\\Background\\upperbg05.bmp", 
"images\\Level 2\\Background\\upperbg06.bmp", 
"images\\Level 2\\Background\\upperbg07.bmp", 
"images\\Level 2\\Background\\upperbg08.bmp", 
"images\\Level 2\\Background\\upperbg09.bmp", 
"images\\Level 2\\Background\\upperbg10.bmp"};
char lowerbglvl2[10][50] = {"images\\Level 2\\Background\\lowerbg01.bmp",
"images\\Level 2\\Background\\lowerbg02.bmp", 
"images\\Level 2\\Background\\lowerbg03.bmp", 
"images\\Level 2\\Background\\lowerbg04.bmp", 
"images\\Level 2\\Background\\lowerbg05.bmp", 
"images\\Level 2\\Background\\lowerbg06.bmp", 
"images\\Level 2\\Background\\lowerbg07.bmp", 
"images\\Level 2\\Background\\lowerbg08.bmp", 
"images\\Level 2\\Background\\lowerbg09.bmp", 
"images\\Level 2\\Background\\lowerbg10.bmp" };
char upperbglvl3[10][50] = { "images\\Level 3\\Background\\upperbg01.bmp",
"images\\Level 3\\Background\\upperbg02.bmp",
"images\\Level 3\\Background\\upperbg03.bmp",
"images\\Level 3\\Background\\upperbg04.bmp",
"images\\Level 3\\Background\\upperbg05.bmp",
"images\\Level 3\\Background\\upperbg06.bmp",
"images\\Level 3\\Background\\upperbg07.bmp",
"images\\Level 3\\Background\\upperbg08.bmp",
"images\\Level 3\\Background\\upperbg09.bmp",
"images\\Level 3\\Background\\upperbg10.bmp" };
char lowerbglvl3[10][50] = {"images\\Level 3\\Background\\lowerbg01.bmp",
"images\\Level 3\\Background\\lowerbg02.bmp", 
"images\\Level 3\\Background\\lowerbg03.bmp", 
"images\\Level 3\\Background\\lowerbg04.bmp", 
"images\\Level 3\\Background\\lowerbg05.bmp", 
"images\\Level 3\\Background\\lowerbg06.bmp", 
"images\\Level 3\\Background\\lowerbg07.bmp", 
"images\\Level 3\\Background\\lowerbg08.bmp", 
"images\\Level 3\\Background\\lowerbg09.bmp", 
"images\\Level 3\\Background\\lowerbg10.bmp" };
char lowerbglvl4[10][60] = { "images\\Level 4\\Background\\LowerBg\\lowerbg01.bmp",
"images\\Level 4\\Background\\LowerBg\\lowerbg02.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg03.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg04.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg05.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg06.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg07.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg08.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg09.bmp", 
"images\\Level 4\\Background\\LowerBg\\lowerbg10.bmp" };
char upperbglvl4[10][60] = {"images\\Level 4\\Background\\UpperBg\\upperbg01.bmp",
"images\\Level 4\\Background\\UpperBg\\upperbg02.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg03.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg04.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg05.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg06.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg07.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg08.bmp", 
"images\\Level 4\\Background\\UpperBg\\upperbg09.bmp",
"images\\Level 4\\Background\\UpperBg\\upperbg10.bmp" };
char menubuttons[5][50] = {"images\\Menu\\Play.bmp",
"images\\Menu\\option.bmp",
"images\\Menu\\Score.bmp",
"images\\Menu\\about us.bmp",
"images\\Menu\\exit.bmp" };
#endif