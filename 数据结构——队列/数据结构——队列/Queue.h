#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QEDataType;
typedef struct QueueNode
{
	QEDataType data;
	struct QueueNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* qn);//初始化队列

void QueueDistory(Queue* qn);//销毁队列

void QueuePrint(Queue* qn);//打印数据

void QueuePush(Queue* qn, QEDataType x);//从尾部向队列插入数据(入队列)

void QueuePop(Queue* qn);//从头部删除队列数据（出队列）

QEDataType QueueFront(Queue* qn);//获取队列头部数据

QEDataType QueueBack(Queue* qn);//获取队列尾部数据

int QueueSize(Queue* qn);//获取队列中的元素个数

int QueueEmpty(Queue* qn);//判断队列是否为空，为空返回非0值，非空则返回0