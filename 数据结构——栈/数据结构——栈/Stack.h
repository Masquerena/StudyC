#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//数据
	int top;//栈顶
	int capacity;//容量
}Stack;

void StackInit(Stack* st);//数据初始化

void StackDistory(Stack* st);//数据销毁

void StackPrint(Stack* st);//数据打印

void StackPush(Stack* st, STDataType x);//从栈顶插入数据并放到栈底(入栈)

void StackPop(Stack* st);//删除栈顶数据（出栈）

STDataType StackTop(Stack* st);//获取栈顶数据

size_t StackSize(Stack* st);//获取栈中有效元素个数

bool StackEmpty(Stack* st);//检测栈是否为空，为空返回非0结果，不为空返回0
