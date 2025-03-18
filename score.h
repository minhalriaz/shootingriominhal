#ifndef SCORE_INCLUDED
#define SCORE_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE 
#include<iostream>
#include "Variables.h"
using namespace std;
int len;
int all_scores[100], max = 10;
char score_text[100], c;
class gamescores{
public :
	int score;
};
gamescores gscore[100];
char* stringConverter(int killPoint){
	char *ch = new char[200];
	itoa(killPoint, ch, 10);
	return ch;
}
void highscore(int kills){
	FILE *fp = fopen("images\\Score\\score.txt", "a");
	if (fp == NULL) {}
	else{
			fprintf(fp, "%s\n",stringConverter(kills));
			fclose(fp);
	}
}
void showScore(){
	int x = 100, y = 650;
	for (int i = 0; i <len; i++){
		cout << gscore[i].score << endl;
		strcpy(score_text, stringConverter(gscore[i].score));
		iSetColor(255, 0, 0);
		iText(x, y, score_text, GLUT_BITMAP_TIMES_ROMAN_24);
		y -= 50;
		max--;
		if (max <= 0) break;
	}
}

/*void highscores(){
	FILE *fp = fopen("images\\Score\\score.txt", "r");
	int j = 0;
while (!feof(fp)){
		fgets(playernames[j], 500 , fp);
		fgets(scores[j], 500, fp);
	}
	
 char ch; int i = 0, k = 0, j = 0 ;
	while ((ch = fgetc(fp)) != EOF)
		cout << "!" << ch << "! ";
	cout <<"\n";
	while ((ch = fgetc(fp)) != EOF){
		//ut << i << "@\n";
		if (ch == '\n'){
			k = 0;
			if (i == 0) i = 1;
			else if (i == 1) {
				i = 0; j++;
			}
			cout << "!!\n";
		}
		if (i == 0){
			playernames[j][k] = ch;
			k++;
		}
		else{
			scores[j][k] = ch;
			k++;
		}
		//cout << j << "\n";
//cout << playernames[j] << " " << scores[j] << endl;
//cout << ch << endl;
	}
	
	fclose(fp);
	tem = j;
	if (i>10) FILE *fp = fopen("images\\Score\\score.txt", "w");
}*/
/*void showHighScore(){

	FILE* fp;
	char str[50];
	fp = fopen("images\\Score\\score.txt", "a+"); // reading the file in append mode
	string scores;
	int all_scores[100];
	int i = 0;

	if (NULL == fp) {
		printf("file can't be opened \n");
	}


	while (fgets(str, 50, fp) != NULL) {
		//printf("%s", str);
		//scores += str;
		if (str != "\n"){
			all_scores[i++] = atoi(str); //converting the string into integer and storing it in an array

		}
	}
	fclose(fp);
	int len = i, a;

	//sorting in descending order to determine high scores...

	for (i = 0; i < len; ++i){
		for (int j = i + 1; j < len; ++j)
		{
			if (all_scores[i] < all_scores[j])
			{
				a = all_scores[i];
				all_scores[i] = all_scores[j];
				all_scores[j] = a;
			}
		}

	}




	int space = 100, max_scores = 10;
	char score_text[1000], c;

	for (int i = 0; i < len; i++){
		strcpy_s(score_text, stringConverter(all_scores[i])); // converting the ints to string first and then char array
		iText(screenWidth / 2 - 50, screenHeight - (space), score_text, GLUT_BITMAP_TIMES_ROMAN_24); // rendering it on display
		space += 30; // space for the next score
		max_scores--; // if it reaches 0, it means total 10 scores have been painted
		if (max_scores <= 0){
			break;
		}

	}


}*/
void highScores(){
	FILE* fp;
	//char str[50];
	fp = fopen("images\\Score\\score.txt", "a+"); // reading the file in append mode
	//string scores;
	int i = 0;

	if (NULL == fp) {
		printf("file can't be opened \n");
	}
	/*while (fgets(str, 50, fp) != NULL) {
		//printf("%s", str);
		//scores += str;
		if (str != "\n"){
			all_scores[i++] = atoi(str); //converting the string into integer and storing it in an array
		}
	}*/
	while (!feof(fp)){
		fscanf(fp, "%d", &gscore[i++].score);
	}
	fclose(fp);
	len = i; int a;

	//sorting in descending order to determine high scores...

	/*for (i = 0; i < len-1; i++){
		for (int j = i + 1; j < len; j++)
		{
			if (all_scores[i] < all_scores[j])
			{
				a = all_scores[i];
				all_scores[i] = all_scores[j];
				all_scores[j] = a;
			}
		}

	}*/
	for (int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			if (gscore[i].score < gscore[j].score){
				a = gscore[i].score;
				gscore[i].score = gscore[j].score;
				gscore[j].score = a;
			}
		}
	}
}
void scoreCounter(){
	iSetColor(255, 0, 0);
	iText(1400, 750, "Score :", GLUT_BITMAP_HELVETICA_18);
	iText(1480, 750, stringConverter(killScore), GLUT_BITMAP_HELVETICA_18);
}

#endif