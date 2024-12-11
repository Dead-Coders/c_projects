#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "graphics.h"
#define PACMAN 4
#define GHOST 3
#define BIG 2
#define FOOD 0
#define BOSLUK 9
#define FRUIT 12
#define KEY_DOWN   80
#define KEY_RIGHT  77
#define KEY_LEFT   75
#define KEY_UP     72
FILE *playerscoreread;
FILE *playerscorewrite;
void menu();
void map();
void start();
void pacman();
void pacmanmove();
void life();
void image(int, int, int);
void ghostsmove();
void ghostsmoveblue();
void freeze(int);
void score(int);
void scoretab();
void theend();
void oldplace();
void fornewgame(int);
void homepage();
void sort();
void food(int wall[23][25], int);
int kpcontrol(int );
int place[23][25];
int random, step = 0, foodscore = 0, oldrc[23][25], pacmanlife = 3 ;
int i = 30, k, yemsatir, yemsutun, satir, sutun, x1 = 0, x2 = 30, y2 = 30, x3 = 0, y3 = 0, x4 = 30, y4 = 30,eskiyon;
struct Score
{
	char name[10];
	int mark;
}people[5];
int sound = 1, off = 0; //x,y,go1  x,y,go2   x,y,go3    x,y,go4   x,y,pacman
int pervar[5][2] = { { 30, 30 }, { 690, 30 }, { 360, 240 }, { 420, 240 }, { 390, 480 } };
int perrc[5][2] = { { 1, 1 }, { 1, 23 }, { 8, 12 }, { 8, 14 }, { 16, 13 } };
char scorestair[6], tus = 0, tusfreeze = 0,stair[5],sta[2];
/*      //GHOST2 Coordinates
bar(690,30,720,60);
//GHOST3 Coordinates
bar(360,240,390,270);
//GHOST4 Coordinates
bar(420,240,450,270);*/
int wall[23][25] = {//330,270,450,360
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },//1
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },//2
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },//3
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1 },//4
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },//5
	{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1 },//6
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1 },//7
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },//8
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 12, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },//9
	{ 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },//10
	{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },//11
	{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1 },//12
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1 },//13
	{ 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 },//14
	{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1 },//15
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },//16
	{ 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1 },//17 
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1 },//18 
	{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },//19
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 2, 1 },//20
	{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },//21
	{ 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },//22
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }//23
}; //3. for ghosts //4. for pacman // 13. 16. PACMAN
void main()
{
	initwindow(1000, 700, "PACMAN");
	fornewgame(1);
	menu();
	getchar();
}
void homepage()
{
	int i, j, k, kop;
	readimagefile("yazý.bmp", 75, 50, 925, 200);
	setcolor(WHITE);
	circle(825, 250, 6);
	for (i = 0; i <= 880; i = i + 10)
	{
		setfillstyle(1, BLACK);
		bar(i - 20, 230, i, 280);
		bar(i, 230, i + 40, 270);
		readimagefile("right.bmp", i, 230, i + 40, 270);
		delay(5);
		if (i < 765)
		{
			readimagefile("ghosts.bmp", i - 200, 230, i - 20, 270);
			setfillstyle(1, BLACK);
			bar(i - 230, 230, i - 200, 270);
		}
		if (i == 760)
		{
			for (j = 825; j >= 0; j -= 20)
			{
				kop = j;
				kop = kop / 2 - 150;
				setfillstyle(1, BLACK);
				bar(i - 180, 230, i + 40, 280);
				readimagefile("blueghosts.bmp", kop + 205, 230, kop - 5, 270);
				readimagefile("left.bmp", j - 40, 230, j, 270);
				bar(j, 230, j + 300, 280);
				if (j <300)
				{
					settextstyle(9, 0, 1);
					outtextxy(j + 50, 240, "200");
				}
				else if (j <400)
				{
					settextstyle(9, 0, 1);
					outtextxy(j + 50, 240, "150");
				}
				else if (j <500)
				{
					settextstyle(9, 0, 1);
					outtextxy(j + 50, 240, "100");
				}
				else if (j < 600)
				{
					settextstyle(9, 0, 1);
					outtextxy(j + 50, 240, "50");
				}
				setfillstyle(1, BLACK);
				delay(100);
			}
			setfillstyle(1, BLACK);
			bar(0, 230, 50, 280);
			bar(0, 230, 250, 280);
			break;
		}
	}
	delay(5);
	//for blinky
	for (i = 500; i >= 350; i = i - 5)
	{
		readimagefile("blinky.bmp", i, 320, i + 30, 350);
		delay(10);
		setfillstyle(1, BLACK);
		bar(i + 30, 320, i + 40, 350);
		delay(5);
	}
	settextstyle(9, 0, 1);
	setcolor(RED);
	outtextxy(500, 335, "BLINKY");
	//for inkey 
	for (i = 500; i >= 350; i = i - 5)
	{
		readimagefile("inkey.bmp", i, 360, i + 30, 390);
		delay(5);
		setfillstyle(1, BLACK);
		bar(i + 60, 360, i + 30, 390);
		delay(5);
	}
	settextstyle(9, 0, 1);
	setcolor(CYAN);
	outtextxy(500, 375, "INKEY");
	//for clyde
	for (i = 500; i >= 350; i = i - 5)
	{
		readimagefile("clyde.bmp", i, 400, i + 30, 430);
		delay(5);
		setfillstyle(1, BLACK);
		bar(i + 60, 400, i + 30, 430);
		delay(5);
	}
	settextstyle(9, 0, 1);
	setcolor(YELLOW);
	outtextxy(500, 415, "CLYDE");
	//for pinky
	for (i = 500; i >= 350; i = i - 5)
	{
		readimagefile("pinky.bmp", i, 440, i + 30, 470);
		delay(5);
		setfillstyle(1, BLACK);
		bar(i + 60, 440, i + 30, 470);
		delay(5);
	}
	settextstyle(9, 0, 1);
	setcolor(LIGHTRED);
	outtextxy(500, 455, "PINKY");
	settextstyle(9, 0, 2);
	setcolor(YELLOW);
	outtextxy(400, 550, "Please Press Any Key....");
	settextstyle(9, 0, 1);
	setcolor(BLUE);
	outtextxy(100, 650, "Cansu YAÞAR");
	outtextxy(400, 650, "Serhat ATAMAN");
	outtextxy(750, 650, "Ebru KAPAN");
	while (1)
	{
		k = getch();
		if (k != 13)
		{
			cleardevice();
			break;
		}
	}
}
void menu()
{
	int x, y, foodscore = 0;
	homepage();
	cleardevice();
	while (1)
	{
		readimagefile("giris.bmp", 10, 10, 950, 250);
		settextstyle(1, 0, 6);
		setcolor(2);
		outtextxy(200, 300, "Play");
		setcolor(3);
		outtextxy(200, 380, "Score");
		setcolor(4);
		outtextxy(200, 460, "How to play");
		setcolor(5);
		outtextxy(200, 540, "Settings");
		setcolor(6);
		outtextxy(200, 620, "Exit");

		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x >= 200 && x <= 400 && y >= 300 && y <= 350)
		{
			if (sound != 0)
				PlaySoundA("Enter.wav", NULL, SND_ASYNC);
			cleardevice();
			map();
			pacman();
		}
		else if (x >= 300 && x <= 500 && y >= 380 && y <= 430)
		{
			if (sound != 0)
				PlaySoundA("Enter.wav", NULL, SND_ASYNC);
			sort();
		}
		else if (x >= 200 && x <= 600 && y >= 460 && y <= 510)
		{
			if (sound != 0)
				PlaySoundA("Enter.wav", NULL, SND_ASYNC);
			cleardevice();
			setcolor(2);
			settextstyle(1, 0, 7);
			outtextxy(50, 50, "HOW TO PLAY");
			setcolor(4);
			settextstyle(1, 0, 3);
			outtextxy(60, 150, "Use the arrow keys to move, avoid");
			outtextxy(60, 190, "the ghosts. Get powerups and you");
			outtextxy(60, 230, "can turn around to catch the");
			outtextxy(60, 270, "ghosts. Some of the ghosts move");
			outtextxy(60, 310, "faster than others. Each ghost has");
			outtextxy(60, 350, "different rules for how they track");
			outtextxy(60, 390, "you. Bonus items can help get you");
			outtextxy(60, 430, "extra lives.");
			setcolor(3);
			settextstyle(1, 0, 7);
			outtextxy(300, 490, "Go back");
			while (1){
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x >= 300 && x <= 650 && y >= 490 && y <= 540){
					if (sound != 0)
						PlaySoundA("Exit.wav", NULL, SND_ASYNC);
					cleardevice();
					break;
				}
			}
		}
		else if (x >= 200 && x <= 400 && y >= 540 && y <= 590)
		{
			if (sound != 0)
				PlaySoundA("Enter.wav", NULL, SND_ASYNC);
			cleardevice();
			setcolor(2);
			settextstyle(1, 0, 7);
			outtextxy(200, 50, "SETTINGS");
			setcolor(3);
			settextstyle(1, 0, 7);
			outtextxy(200, 490, "Go back");
			settextstyle(1, 0, 5);
			if (sound != 0)
			{
				setfillstyle(1, BLACK);
				bar(200, 300, 570, 350);
				setcolor(12);
				outtextxy(250, 300, "Sound on");
			}
			else
			{
				setfillstyle(1, BLACK);
				bar(200, 300, 570, 350);
				setcolor(12);
				outtextxy(250, 300, "Sound off");
			}
			while (1)
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x >= 200 && y >= 300 && x <= 570 && y <= 350)
				{
					off = off % 2;
					if (off != 0)
					{
						setfillstyle(1, BLACK);
						bar(200, 300, 570, 350);
						settextstyle(1, 0, 5);
						setcolor(12);
						outtextxy(250, 300, "Sound on");
						PlaySoundA("Enter.wav", NULL, SND_ASYNC);
						sound = 1;
						off = 0;
					}
					else if (off == 0)
					{
						setfillstyle(1, BLACK);
						bar(200, 300, 570, 350);
						settextstyle(1, 0, 5);
						setcolor(12);
						outtextxy(250, 300, "Sound off");
						sound = 0;
						off = 1;
					}
				}
				else if (x >= 200 && x <= 560 && y >= 490 && y <= 540)
				{
					if (sound != 0)
						PlaySoundA("Exit.wav", NULL, SND_ASYNC);
					cleardevice();
					break;
				}
			}
		}
		else if (x >= 200 && x <= 400 && y >= 620 && y <= 670)
		{
			if (sound != 0)
				PlaySoundA("Exit.wav", NULL, SND_ASYNC);
			delay(600);
			freeze(3);
		}
	}
}
void score(int a)
{
	if (a == 0)
		foodscore += 10;
	else if (a == 2)
		foodscore += 30;
	else if (a == 12)
	{
		setfillstyle(1, BLACK); bar(390, 240, 420, 270);
		foodscore += 90;
	}
	setcolor(11);
	settextstyle(1, 0, 5);
	outtextxy(777, 80, itoa(foodscore, scorestair, 10));
}
void map()
{
	for (satir = 0; satir < 23; ++satir)
	{
		for (sutun = 0; sutun < 25; ++sutun)
		{
			if (wall[satir][sutun] == 1)
			{
				setfillstyle(9, 5);
				bar(sutun * 30, satir * 30, sutun * 30 + 30, satir * 30 + 30);
			}
		}
	}
	food(wall, FOOD);
	food(wall, BIG);
	if (step >= 60)
		food(wall, FRUIT);
	setcolor(11);
	settextstyle(1, 0, 4);
	outtextxy(790, 40, "SCORE");
	rectangle(755, 70, 980, 130);
	setcolor(12);
	outtextxy(810, 200, "LIFE");
	rectangle(755, 230, 980, 290);
	setcolor(6);
	rectangle(755, 390, 980, 450);
	if (pacmanlife == 3)
	{
		readimagefile("pacmanlife.bmp", 775, 240, 835, 280);//Life photos
		readimagefile("pacmanlife.bmp", 835, 240, 895, 280);
		readimagefile("pacmanlife.bmp", 895, 240, 955, 280);
	}
	else if (pacmanlife == 2)
	{
		readimagefile("pacmanlife.bmp", 775, 240, 835, 280);//Life photos
		readimagefile("pacmanlife.bmp", 835, 240, 895, 280);
		setfillstyle(1, 0);
		bar(895, 240, 955, 280);
	}
	else if (pacmanlife == 1)
	{
		readimagefile("pacmanlife.bmp", 775, 240, 835, 280);//Life photos
		setfillstyle(1, 0);
		bar(835, 240, 895, 280);
	}
	else if (pacmanlife == 0){
		setfillstyle(1, 0);
		bar(775, 240, 835, 280);//Life photos
	}
	readimagefile("fruit2.bmp", 835, 395, 895, 445);//fruit
}
void food(int wall[23][25], int a)
{
	if (a == FOOD)//SMALL FOOD
	{
		x3 = 0;
		y3 = 0;
		x4 = 30;
		y4 = 30;
		setcolor(WHITE);
		for (yemsatir = 0; yemsatir < 23; yemsatir++)
		{
			for (yemsutun = 0; yemsutun < 25; yemsutun++)
			{
				if (wall[yemsatir][yemsutun] == 0)
				{
					circle((x3 + x4) / 2, (y3 + y4) / 2, 3);
				}
				x4 += 30;
				x3 += 30;
			}
			x3 = 0;
			x4 = 30;
			y3 += 30;
			y4 += 30;
		}
	}
	else if (a == BIG){//BIG FOOD
		x3 = 0;
		y3 = 0;
		x4 = 30;
		y4 = 30;
		setcolor(WHITE);
		for (yemsatir = 0; yemsatir < 23; yemsatir++)
		{
			for (yemsutun = 0; yemsutun < 25; yemsutun++)
			{
				if (wall[yemsatir][yemsutun] == 2)
				{
					circle((x3 + x4) / 2, (y3 + y4) / 2, 6);
				}
				x4 += 30;
				x3 += 30;
			}
			x3 = 0;
			x4 = 30;
			y3 += 30;
			y4 += 30;
		}
	}
	else if (a == FRUIT)
		readimagefile("fruit2.bmp", 390, 240, 420, 266);
}
void start()
{
	while (1){
		setfillstyle(1, 0);
		setcolor(6);
		settextstyle(1, 0, 9);
		outtextxy(365, 300, "3"); delay(900);
		settextstyle(1, 0, 9);
		outtextxy(365, 300, "2"); delay(900);
		settextstyle(1, 0, 9);
		outtextxy(365, 300, "1"); delay(900);
		settextstyle(1, 0, 8);
		outtextxy(310, 300, "GO"); delay(900);
		tus = getch();
		if (tus != 13)
			break;
	}
	cleardevice();
	map();
}
void pacman()
{
	start();
	pacmanmove();
}
void pacmanmove(){
	while (1)
	{
		tus = getch();
		if (tus == 75)//KEY_LEFT
		{
			while (wall[perrc[4][0]][perrc[4][1] - 1] != 1){
				(step>100) ? delay(30) : delay(100);	// SPEED
				if (wall[perrc[4][0]][perrc[4][1] - 1] == 0)
					score(0);
				else if (wall[perrc[4][0]][perrc[4][1] - 1] == 12)
					score(12);
				readimagefile("left.bmp", pervar[4][0] - i, pervar[4][1], (pervar[4][0] + 30) - i, (pervar[4][1] + 30));
				setfillstyle(1, 0);
				bar(pervar[4][0], pervar[4][1], (pervar[4][0] + 30), (pervar[4][1] + 30));
				wall[perrc[4][0]][perrc[4][1] - 1] = BOSLUK;
				pervar[4][0] -= i;
				perrc[4][1]--;
				step++;
				if (wall[perrc[4][0]][perrc[4][1] - 1] == 2)
				{
					score(2);
					ghostsmoveblue();
				}
				else ghostsmove();
				if ((pervar[4][0] == pervar[0][0] && pervar[4][1] == pervar[0][1]) || (pervar[4][0] == pervar[1][0] && pervar[4][1] == pervar[1][1]) ||
					(pervar[4][0] == pervar[2][0] && pervar[4][1] == pervar[2][1]) || (pervar[4][0] == pervar[3][0] && pervar[4][1] == pervar[3][1]))
				{
					life();
					break;
				}
				if (kbhit())
				{
					eskiyon = 75;
					kpcontrol(eskiyon);
					break;
				}
			}
		}
		else if (tus == 77)//KEY_RIGHT
		{
			while (wall[perrc[4][0]][perrc[4][1] + 1] != 1){
				(step>100) ? delay(30) : delay(100);	// SPEED
				if (wall[perrc[4][0]][perrc[4][1] + 1] == 0)
					score(0);
				else if (wall[perrc[4][0]][perrc[4][1] + 1] == 12)
					score(12);
				readimagefile("right.bmp", pervar[4][0] + i, pervar[4][1], (pervar[4][0] + 30) + i, (pervar[4][1] + 30));
				setfillstyle(1, 0);
				bar(pervar[4][0], pervar[4][1], (pervar[4][0] + 30), (pervar[4][1] + 30));
				wall[perrc[4][0]][perrc[4][1] + 1] = BOSLUK;
				pervar[4][0] += i;
				perrc[4][1]++;
				step++;
				if (wall[perrc[4][0]][perrc[4][1] + 1] == 2)
				{
					score(2);
					ghostsmoveblue();
				}
				else ghostsmove();
				if ((pervar[4][0] == pervar[0][0] && pervar[4][1] == pervar[0][1]) || (pervar[4][0] == pervar[1][0] && pervar[4][1] == pervar[1][1]) ||
					(pervar[4][0] == pervar[2][0] && pervar[4][1] == pervar[2][1]) || (pervar[4][0] == pervar[3][0] && pervar[4][1] == pervar[3][1]))
				{
					life();
					break;
				}
				if (kbhit())
				{
					eskiyon = 77;
					kpcontrol(eskiyon);
					break;
				}
			}
		}
		else if (tus == 72)//KEY_UP
		{
			while (wall[perrc[4][0] - 1][perrc[4][1]] != 1){
				(step>100) ? delay(30) : delay(100);	// SPEED
				if (wall[perrc[4][0] - 1][perrc[4][1]] == 0)
					score(0);
				else if (wall[perrc[4][0] - 1][perrc[4][1]] == 12)
					score(12);
				readimagefile("up.bmp", pervar[4][0], pervar[4][1] - i, (pervar[4][0] + 30), (pervar[4][1] + 30) - i);
				setfillstyle(1, 0);
				bar(pervar[4][0], pervar[4][1], (pervar[4][0] + 30), (pervar[4][1] + 30));
				wall[perrc[4][0] - 1][perrc[4][1]] = BOSLUK;
				pervar[4][1] -= i;
				perrc[4][0]--;
				step++;
				if (wall[perrc[4][0] - 1][perrc[4][1]] == 2){
					score(2);
					ghostsmoveblue();
				}
				else ghostsmove();
				if ((pervar[4][0] == pervar[0][0] && pervar[4][1] == pervar[0][1]) || (pervar[4][0] == pervar[1][0] && pervar[4][1] == pervar[1][1]) ||
					(pervar[4][0] == pervar[2][0] && pervar[4][1] == pervar[2][1]) || (pervar[4][0] == pervar[3][0] && pervar[4][1] == pervar[3][1]))
				{
					life();
					break;
				}
				if (kbhit())
				{
					eskiyon = 72;
					kpcontrol(eskiyon);
					break;
				}
			}
		}
		else if (tus == 80)//KEY_DOWN
		{
			while (wall[perrc[4][0] + 1][perrc[4][1]] != 1){
				(step>100) ? delay(30) : delay(100);	// SPEED
				if (wall[perrc[4][0] + 1][perrc[4][1]] == 0)
					score(0);
				else if (wall[perrc[4][0] + 1][perrc[4][1]] == 12)
					score(12);
				readimagefile("down.bmp", pervar[4][0], pervar[4][1] + i, (pervar[4][0] + 30), (pervar[4][1] + 30) + i);
				setfillstyle(1, 0);
				bar(pervar[4][0], pervar[4][1], (pervar[4][0] + 30), (pervar[4][1] + 30));
				wall[perrc[4][0] + 1][perrc[4][1]] = BOSLUK;
				pervar[4][1] += i;
				perrc[4][0]++;
				step++;
				if (wall[perrc[4][0] + 1][perrc[4][1]] == 2){
					score(2);
					ghostsmoveblue();
				}
				else ghostsmove();
				if ((pervar[4][0] == pervar[0][0] && pervar[4][1] == pervar[0][1]) || (pervar[4][0] == pervar[1][0] && pervar[4][1] == pervar[1][1]) ||
					(pervar[4][0] == pervar[2][0] && pervar[4][1] == pervar[2][1]) || (pervar[4][0] == pervar[3][0] && pervar[4][1] == pervar[3][1]))
				{
					life();
					break;
				}
				if (kbhit())
				{
					eskiyon = 80;
					kpcontrol(eskiyon);
					break;
				}
			}
		}
	}
}
void ghostsmove()
{
	for (k = 0; k < 4; k++)
	{
		if (perrc[k][0]<perrc[4][0])//DOWN
		{
			if (wall[perrc[k][0] + 1][perrc[k][1]] != 1){
				setfillstyle(1, 4);
				image(1, k, 0);
				pervar[k][1] += i;
				setfillstyle(1, 0);
				bar(pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i);
				perrc[k][0]++;

				map();
			}
		}
		if (perrc[k][0]>perrc[4][0])//UP
		{
			if (wall[perrc[k][0] - 1][perrc[k][1]] != 1){
				setfillstyle(1, 4);
				image(1, k, 1);
				pervar[k][1] -= i;
				setfillstyle(1, 0);
				bar(pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i);
				perrc[k][0]--;
				map();
			}
		}
		if (perrc[k][1]>perrc[4][1])//LEFT
		{
			if (wall[perrc[k][0]][perrc[k][1] - 1] != 1){
				setfillstyle(1, 4);
				image(1, k, 2);
				pervar[k][0] -= i;
				setfillstyle(1, 0);
				bar(pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30));
				perrc[k][1]--;
				map();
			}
		}
		if (perrc[k][1]<perrc[4][1])//RIGHT
		{
			if (wall[perrc[k][0]][perrc[k][1] + 1] != 1){
				setfillstyle(1, 4);
				image(1, k, 3);
				pervar[k][0] += i;
				setfillstyle(1, 0);
				bar(pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30));
				perrc[k][1]++;
				map();
			}
		}
	}
}
void ghostsmoveblue()
{
	int walkback = 0;
	for (walkback = 0; walkback < 15; ++walkback)
	{
		for (k = 0; k <4; ++k)
		{
			if (perrc[k][0]>perrc[4][0])//DOWN
			{
				if (wall[perrc[k][0] + 1][perrc[k][1]] != 1){
					setfillstyle(1, 4);
					image(2, k, 0);
					pervar[k][1] += i;
					setfillstyle(1, 0);
					bar(pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i);
					perrc[k][0]++;
					map();
				}
			}
			if (perrc[k][0]<perrc[4][0])//UP
			{
				if (wall[perrc[k][0] - 1][perrc[k][1]] != 1){
					setfillstyle(1, 4);
					image(2, k, 1);
					pervar[k][1] -= i;
					setfillstyle(1, 0);
					bar(pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i);
					perrc[k][0]--;
					map();
				}
			}
			if (perrc[k][1]<perrc[4][1])//LEFT
			{
				if (wall[perrc[k][0]][perrc[k][1] - 1] != 1){
					setfillstyle(1, 4);
					image(2, k, 2);
					pervar[k][0] -= i;
					setfillstyle(1, 0);
					bar(pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30));
					perrc[k][1]--;
					map();
				}
			}
			if (perrc[k][1]>perrc[4][1])//RIGHT
			{
				if (wall[perrc[k][0]][perrc[k][1] + 1] != 1){
					setfillstyle(1, 4);
					image(2, k, 3);
					pervar[k][0] += i;
					setfillstyle(1, 0);
					bar(pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30));
					perrc[k][1]++;
					map();
				}
			}
		}
	}
}
void image(int j, int k, int l)
{
	if (j == 1){
		switch (k)
		{
		case 0:{
				   switch (l)
				   {
				   case 0:{readimagefile("blinky.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
				   case 1:{readimagefile("blinky.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
				   case 2:{readimagefile("blinky.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
				   case 3:{readimagefile("blinky.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
				   }break; }
		case 1:{switch (l)
		{
		case 0:{readimagefile("pinky.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("pinky.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("pinky.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("pinky.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		case 2:{switch (l)
		{
		case 0:{readimagefile("clyde.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("clyde.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("clyde.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("clyde.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		case 3:{switch (l)
		{
		case 0:{readimagefile("inkey.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("inkey.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("inkey.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("inkey.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		}
	}
	else{
		switch (k){
		case 0:{
				   switch (l)
				   {
				   case 0:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
				   case 1:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
				   case 2:{readimagefile("blue.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
				   case 3:{readimagefile("blue.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
				   }break; }
		case 1:{switch (l)
		{
		case 0:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("blue.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("blue.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		case 2:{switch (l)
		{
		case 0:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("blue.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("blue.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		case 3:{switch (l)
		{
		case 0:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] + i, (pervar[k][0] + 30), (pervar[k][1] + 30) + i); break; }
		case 1:{readimagefile("blue.bmp", pervar[k][0], pervar[k][1] - i, (pervar[k][0] + 30), (pervar[k][1] + 30) - i); break; }
		case 2:{readimagefile("blue.bmp", pervar[k][0] - i, pervar[k][1], (pervar[k][0] + 30) - i, (pervar[k][1] + 30)); break; }
		case 3:{readimagefile("blue.bmp", pervar[k][0] + i, pervar[k][1], (pervar[k][0] + 30) + i, (pervar[k][1] + 30)); break; }
		}break; }
		}
	}
}
void life()
{
	pacmanlife--;
	switch (pacmanlife)
	{
	case 2:{setfillstyle(1, BLACK); bar(895, 240, 955, 280); oldplace(); break; }
	case 1:{setfillstyle(1, BLACK); bar(835, 240, 895, 280); oldplace(); break; }
	case 0:{setfillstyle(1, BLACK);
		bar(775, 240, 835, 280);
		pacmanlife = 3;
		oldplace();
		fornewgame(2);
		theend();
		break; }
	}
}
void theend()
{
	scoretab();
	menu();
}
void oldplace()
{//Yeni oyun olduðunda eski yerlerin gözükmesi için 
	for (k = 0; k<4; ++k){
		wall[perrc[k][0]][perrc[k][1]] = place[perrc[k][0]][perrc[k][1]];
		setfillstyle(1, 0); //Önceki yerlerinin silinmesi için
		bar(pervar[k][0], pervar[k][1], (pervar[k][0] + 30), (pervar[k][1] + 30));
	}
	pervar[0][0] = 30; pervar[0][1] = 30; pervar[1][0] = 690; pervar[1][1] = 30; pervar[2][0] = 360;
	pervar[2][1] = 240; pervar[3][0] = 420; pervar[3][1] = 240; pervar[4][0] = 390; pervar[4][1] = 480;

	perrc[0][0] = 1; perrc[0][1] = 1; perrc[1][0] = 1; perrc[1][1] = 23; perrc[2][0] = 8;
	perrc[2][1] = 12; perrc[3][0] = 8; perrc[3][1] = 14; perrc[4][0] = 16; perrc[4][1] = 13;
	map();
	for (k = 0; k < 4; ++k)
	{
		setfillstyle(1, 4);
		bar(pervar[k][0], pervar[k][1], (pervar[k][0] + 30), (pervar[k][1] + 30));
	}
	setfillstyle(1, 14);
	bar(pervar[4][0], pervar[4][1], (pervar[4][0] + 30), (pervar[4][1] + 30));
}
void fornewgame(int old)
{
	int satir = 0, sutun = 0;
	switch (old)
	{
	case 1:
	{
			  for (satir = 0; satir < 23; ++satir)
			  {
				  for (sutun = 0; sutun < 25; ++sutun)
				  {
					  oldrc[satir][sutun] = wall[satir][sutun];
				  }
			  }
			  break; }
	case 2:
	{
			  for (satir = 0; satir < 23; ++satir)
			  {
				  for (sutun = 0; sutun < 25; ++sutun)
				  {
					  wall[sutun][satir] = oldrc[sutun][satir];
				  }
			  }
			  break; }
	}
}
void freeze(int f)
{
	if (f == 1)
	{
		setcolor(10);
		settextstyle(1, 0, 8);
		outtextxy(110, 300, "PAUSED");
		while (1)
		{
			tusfreeze = getch();
			if (tusfreeze == 'p' || tusfreeze == 'P')//Return P
			{
				cleardevice();
				map();
				break;
			}

		}

	}
	else if (f == 2)
	{
		setcolor(10);
		settextstyle(1, 0, 4);
		outtextxy(50, 300, "Are you sure you want to quit the game ?");
		outtextxy(110, 330, "                     Y / N             ");
		while (1)
		{
			tusfreeze = getch();
			if (tusfreeze == 'y' || tusfreeze == 'Y')
				exit(0);
			else if (tusfreeze == 'n' || tusfreeze == 'N')
				break;
		}
		cleardevice();
		map();
	}
	else
	{
		cleardevice();
		setcolor(10);
		settextstyle(1, 0, 4);
		outtextxy(50, 300, "Are you sure you want to quit the game ?");
		outtextxy(110, 330, "                     Y / N             ");
		while (1)
		{
			tusfreeze = getch();
			if (tusfreeze == 'y' || tusfreeze == 'Y')
				exit(0);
			else if (tusfreeze == 'n' || tusfreeze == 'N')
				break;
		}
		cleardevice();
		menu();
	}

}
int kpcontrol(int )
{
	tus = getch();
	if (tus == 'p' || tus == 'P')//Pause
		freeze(1);
	else if (tus == 27)
		freeze(2);
	else if (tus == 77)
	{
		if (eskiyon==tus)
			return(eskiyon);
		return(77);
	}
	else if (tus == 80){
		if (eskiyon == tus)
			return(eskiyon);
		return(80);
	}
	else if (tus == 72){
		if (eskiyon == tus)
			return(eskiyon);
		return(72);
	}
	else if (tus == 75){
		if (eskiyon == tus)
			return(eskiyon);
		return(75);
	}
		
}
void scoretab()
{
	int i, newscore, a = 0, k, l = 20;
	char nickname[15], button;
	cleardevice();
	newscore = foodscore;
	settextstyle(1, 0, 3);
	playerscoreread = fopen("scores.txt", "r");
	for (i = 0; i<5; i++)//Puanlarý okuma
		fscanf(playerscoreread, "%s%d", &people[i].name, &people[i].mark);
	for (i = 0; i<5; i++)//Puan sýralamasý
	if (newscore >= people[i].mark)
		break;
	fclose(playerscoreread);
	for (a = 6; a>i; a--)
	{
		people[a].mark = people[a - 1].mark;
		strcpy(people[a].name, people[a - 1].name);
	}
	a = 0;
	people[i].mark = newscore; //rectangle(100, 390, 800, 440);
	cleardevice();
	setcolor(2);
	settextstyle(1, 0, 7);
	outtextxy(150, 50, "GAME OVER");
	setcolor(1);
	settextstyle(1, 0, 6);
	outtextxy(110, 160, "Your Score :");
	outtextxy(560, 160, itoa(foodscore, scorestair, 10));
	setcolor(14);
	settextstyle(1, 0, 3);
	outtextxy(40, 280, "Please enter your name and click the enter button.");
	setcolor(7);
	settextstyle(1,0,4);
	rectangle(80, 315, 700, 370);
	outtextxy(40,470,"You can not use space button.");
	button = getch();
	if (button != '\0')
	{
		nickname[a] = button;
		nickname[a + 1] = '\0';
	}
	outtextxy(90, 330, nickname);
	a = 0;   
	while (1)
	{
		if (nickname[a] == 32){ a--; setcolor(RED); outtextxy(200, 230, "bosluk birakamazsiniz..."); }
		if (nickname[a] == 13)   break;
		if (nickname[a] == 8)
		{
			a--;
			nickname[a] = 32;
			a--;
			if (a<0)
				a = -1;
		}
		a++;
		if (a == 19)
		{
			a--; setcolor(BLUE);
			outtextxy(200, 200, "En Fazla 20 Karakter Girebilirsiniz...");
		}
		button = getch();
		if (button != '\0')
			nickname[a] = button;
		else
			a--;
		//printf("%c %d \n",c[a],c[a]);
		nickname[a + 1] = '\0';
		outtextxy(90,330,nickname);
	}
	for (a = 0; nickname[a] != '\0'; a++)
		people[i].name[a] = nickname[a];
	people[i].name[a] = '\0';
	playerscorewrite = fopen("scores.txt", "w+");
	for (a = 0; a<5; a++)
		fprintf(playerscoreread, "%s %d\n", people[a].name, people[a].mark);
	fclose(playerscorewrite);
	cleardevice();
	sort();
}
void sort()
{
	int k = 15,l=140,x=50,a,b;
	char stair[5], tus = 0;
	FILE *player;
	player = fopen("scores.txt", "r");
	for (i = 0; i<5; i++)
		fscanf(player, "%s%d", people[i].name, &people[i].mark);
	for (i = 0; i < 5; i++)
	{
		setcolor(13);
		settextstyle(1, 0, 4);
		outtextxy(300, x + l, itoa(i+1, sta, 10));
		outtextxy(350, x+ l, people[i].name);
		outtextxy(630, x+l , itoa(people[i].mark, stair, 10)); 
		x += 50;
	}
	setcolor(2);
	settextstyle(1, 0, 7);
	outtextxy(200, 50, "SCORES");
	setcolor(3);
	settextstyle(1, 0, 7);
	outtextxy(300, 490, "Go back");
	while (1){
		getmouseclick(WM_LBUTTONDOWN, a, b);
		if (a >= 300 && a <= 650 && b >= 490 && b <= 540){
			if (sound != 0)
				PlaySoundA("Exit.wav", NULL, SND_ASYNC);
			cleardevice();
			break;
		}
	}
	fclose(player);
	menu();
}
