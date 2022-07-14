#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

void menu(void);//打印菜单

void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘为空格

void Displayboard(char board[ROW][COL], int row, int col);//打印棋盘

void playermove(char board[ROW][COL], int row, int col);//玩家下棋

void computermove(char board[ROW][COL], int row, int col);//电脑下棋

char iswin(char board[ROW][COL], int row, int col);//判断胜负

int isfull(char board[ROW][COL], int row, int col);//判断棋盘是否满