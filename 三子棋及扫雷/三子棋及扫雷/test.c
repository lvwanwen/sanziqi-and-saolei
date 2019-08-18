/*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void menu()
{
	printf("*********************\n");
	printf("*******1.play********\n");
	printf("*******0.exit*********\n");
	printf("*********************\n");
}
void game()
{
	int ret = 0;
	char board[3][3] = { 0 };
	InitBoard(board, 3, 3);
	//打印棋盘
	ShowBoard(board, 3, 3);
	while (1)
	{
		PlayerMove(board, 3, 3);
		//每次都要判断是否赢了比赛
		ret = IsWin(board, 3, 3);
		if (ret != ' ')
		{
			break;
		}
		ShowBoard(board, 3, 3);
		ComputerMove(board, 3, 3);
		ret = IsWin(board, 3, 3);
		if (ret != ' ')
		{
			break;
		}
		ShowBoard(board, 3, 3);
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
	else if (ret == 'X')
	{
		printf("玩家胜出\n");
	}
	else if (ret == 'O')
	{
		printf("电脑胜出\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("请输入正确的数字\n");
			break;
		}
	} while (input);
	return 0;
}*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void menu()
{
	printf("**********************\n");
	printf("******0.exit***********\n");
	printf("******1.play**********\n");
	printf("***********************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };//存放雷的信息

	char mineInfo[ROWS][COLS] = { 0 };//排查出来的雷信息，没有排查出来的话打印*

	InitBoard(mine, ROWS, COLS, '0');//代表还没有布置雷

	InitBoard(mineInfo, ROWS, COLS, '*');//还没有排查出来雷的情况

	ShowBoard(mineInfo, ROW, COL);//打印二维数组

	SetMine(mine, ROW, COL);//布置雷

	FindMine(mine, mineInfo, ROW, COL);//找雷
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输你的操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出\n");
			break;
		default:
			printf("请输入正确的数字\n");
			break;
		}
	} while (input);
	return 0;
}