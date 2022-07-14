#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define bomb 4

void menu(void);//打印菜单

void initboard(char board[ROWS][COLS], int rows, int cols, char set);//数组初始化

void displayboard(char board[ROWS][COLS], int row, int col);//打印数组

void setmine(char board[ROWS][COLS], int row, int col);//在数组中随机布置雷

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//在mine中排查雷

int get_mine(char mine[ROWS][COLS], int row, int col);//获取输入坐标的周围有几个雷

void test(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);//提供一个可以循环显示为0的坐标的程序