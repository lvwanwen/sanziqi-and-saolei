/*#ifndef __GAME_H__
#define __GAME_H__
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[][3], int row, int col);//初始化棋盘
void ShowBoard(char board[][3], int row, int col);//打印棋盘
void PlayerMove(char board[][3], int row, int col);//玩家移动
int IsWin(char board[][3], int row, int col);//是否赢得了胜利
void ComputerMove(char board[][3], int row, int col);//电脑移动
#endif//!__GAME_H__*/
#ifndef  __GAME_H__
#define  __GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MINE_NUM 10
#define ROW 9
#define COL 9

#define ROWS  ROW+2
#define COLS    COL+2

void InitBoard(char board[][COLS], int rows, int cols, char set);//初始化棋盘
void ShowBoard(char board[][COLS], int row, int col);//打印棋盘
void SetMine(char mine[][COLS], int row, int col);//设置雷
void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col);//扫雷

#endif
