#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//写一个9*9的扫雷游戏
//步骤：写出调试程序，写出运行主程序，定义出两个数组，初始化数组内容，打印数组内容，在数组中的随机生成雷
//程序优化，使该扫雷游戏在输入坐标返回值为0时，依次检验周边坐标的值，若为0，再次检验，若不为0，该不为0的坐标停止检验
void game(void)
{
	char mine[ROWS][COLS] = {0};//声明两个数组
	char show[ROWS][COLS] = {0};

	initboard(mine, ROWS, COLS, '0');//初始化数组内容为字符0
	initboard(show, ROWS, COLS, '*');//初始化数组内容为字符*

	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);//打印数组的内容

	setmine(mine, ROW, COL);//在mine数组中放置雷
	//displayboard(mine, ROW, COL);这里放个打印函数是为了看见雷的位置以方便测试

	findmine(mine, show, ROW, COL);//在mine数组中排查雷，并将结果输入到show函数中。
	                               //即在没有踩到雷时打印show数组，踩到雷时打印mine数组

}


int main(void)
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();

		printf("请选择 >");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("结束\n");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);
	
	return 0;
}