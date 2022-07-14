#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game(void)
{
	char board[ROW][COL];
	char ret = 0;

	InitBoard(board, ROW, COL);//初始化数组为空格

	Displayboard(board, ROW, COL);//打印棋盘

	while (1)
	{
		playermove(board, ROW, COL);//玩家行动
		Displayboard(board, ROW, COL);//打印棋盘
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
			break;

		computermove(board, ROW, COL);//电脑行动
		Displayboard(board, ROW, COL);//打印棋盘
		ret = iswin(board, ROW, COL);//判断胜负。如果玩家赢，返回'*'，如果电脑赢，返回'#'
		                             //如果平局，返回'q'，如果还未决出胜负，返回'c'
		if (ret != 'c')
			break;
	}

	switch (ret)
	{
	case '*':
		printf("玩家获胜\n");
		break;
	case '#':
		printf("电脑获胜\n");
		break;
	case 'q':
		printf("平局\n");
		break;
	}
	Displayboard(board, ROW, COL);
	return;
}

int main(void)//驱动程序，用于测试主程序是否可用
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();

		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		default :
			printf("输入错误，请重新输入：\n");
		}

	} while (input);
	return 0;
}