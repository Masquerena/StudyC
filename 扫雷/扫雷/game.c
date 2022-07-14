#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu(void)
{
	printf("*********************\n");
	printf("*****1.开始游戏******\n");
	printf("*****0.结束游戏******\n");
	printf("*********************\n");
	return;
}

void initboard(char board[ROWS][COLS], int rows, int cols, char set)//数组初始化
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
	return;
}

void displayboard(char board[ROWS][COLS], int row, int col)//打印数组
{
	int i = 0;
	int j = 0;
	
	printf("_____________扫雷____________\n");
	for (i = 0; i <= row;i++)
	{
		printf(" %d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("_____________扫雷____________\n");

	return;
}

void setmine(char board[ROWS][COLS], int row, int col)//在数组随机放置'1'为雷
{
	int count = bomb;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	return;
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (1)
	{
		printf("请输入排查坐标：");

		scanf("%d %d", &x, &y);

		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//判断输入坐标是否合理
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				displayboard(mine, ROW, COL);

				break;
			}
			else
			{
				test(mine, show, x, y, row, col);

				displayboard(show, ROW, COL);

				win++;

				if (win == ROW * COL - bomb)
				{
					printf("恭喜你，获胜了\n");
					displayboard(mine, ROW, COL);

					break;
				}
			}
		}
		else
			printf("无效坐标，请重新输入");
	}

}

int get_mine(char mine[ROWS][COLS], int x, int y)//计算输入的坐标周围一圈内的雷的个数
{
	int i = -1;
	int j = -1;
	int count = 0;
	
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1;j++)
		{
			if (mine[x + i][y + j] == '1')
				count++;
		}
	}
	return count;
}

void test(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y, int row, int col)
{
	int count = get_mine(mine, x, y);

	if (count == 0)
	{
		show[x][y] = count + '0';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= j + 1; j++)
			{			
				if (show[i][j] == '*')
				{
					test(mine, show, i, j, row, col);
				}		
			}
		}
	}
	else
		show[x][y] = count + '0';
}
	