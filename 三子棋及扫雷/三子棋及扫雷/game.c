/*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void InitBoard(char board[][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void ShowBoard(char board[][3], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayerMove(char board[][3], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入1-3的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("此位置已被占用了\n");
			}
		}
		else
		{
			printf("坐标位置不合法\n");
		}
	}
}
static int IsFull(char board[][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
int IsWin(char board[][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1]
			&& board[i][1] == board[i][2]
			&& board[i][0] != ' ')
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&& board[0][i] != ' ')
		{
			return board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
			&& board[0][0] != ' ')
		{
			return board[0][0];
		}

		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
			&& board[0][0] != ' ')
		{
			return board[0][2];
		}
		if (IsFull(board, row, col) == 1)
		{
			return 'Q';
		}
	}
	return ' ';
}
void ComputerMove(char board[][3], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑移动\n");
	while (1)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = 'O';
			break;
		}
	}
}*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
void InitBoard(char board[][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void ShowBoard(char board[][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("===================\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("===================\n");
}
void SetMine(char mine[][COLS], int row, int col)
{
	int x;
	int y;
	int count = 0;
	while (count < MINE_NUM)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
static int GetMineCount(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] +
		mine[x + 1][y - 1] + mine[x][y - 1] - 8 * '0';
}
void FindMine(char mine[][COLS], char mineInfo[][COLS], int row, int col)
{
	int count = 0;
	int x = 0;
	int y = 0;
	while (count < row * col - MINE_NUM)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				ShowBoard(mine, row, col);
				break;
			}
			else
			{
				int ret = GetMineCount(mine, x, y);
				mineInfo[x][y] = ret + '0';
				ShowBoard(mineInfo, row, col);
				count++;
			}
		}
		else
		{
			printf("坐标不合法\n");
		}
	}
}
