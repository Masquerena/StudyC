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

void QueueInit(Queue* qn);//��ʼ������

void QueueDistory(Queue* qn);//���ٶ���

void QueuePrint(Queue* qn);//��ӡ����

void QueuePush(Queue* qn, QEDataType x);//��β������в�������(�����)

void QueuePop(Queue* qn);//��ͷ��ɾ���������ݣ������У�

QEDataType QueueFront(Queue* qn);//��ȡ����ͷ������

QEDataType QueueBack(Queue* qn);//��ȡ����β������

int QueueSize(Queue* qn);//��ȡ�����е�Ԫ�ظ���

int QueueEmpty(Queue* qn);//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ��ط�0ֵ���ǿ��򷵻�0