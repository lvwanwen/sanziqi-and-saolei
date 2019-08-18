/*#ifndef __GAME_H__
#define __GAME_H__
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[][3], int row, int col);//��ʼ������
void ShowBoard(char board[][3], int row, int col);//��ӡ����
void PlayerMove(char board[][3], int row, int col);//����ƶ�
int IsWin(char board[][3], int row, int col);//�Ƿ�Ӯ����ʤ��
void ComputerMove(char board[][3], int row, int col);//�����ƶ�
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

void InitBoard(char board[][COLS], int rows, int cols, char set);//��ʼ������
void ShowBoard(char board[][COLS], int row, int col);//��ӡ����
void SetMine(char mine[][COLS], int row, int col);//������
void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col);//ɨ��

#endif
