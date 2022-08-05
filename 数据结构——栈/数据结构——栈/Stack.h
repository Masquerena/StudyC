#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;//����
	int top;//ջ��
	int capacity;//����
}Stack;

void StackInit(Stack* st);//���ݳ�ʼ��

void StackDistory(Stack* st);//��������

void StackPrint(Stack* st);//���ݴ�ӡ

void StackPush(Stack* st, STDataType x);//��ջ���������ݲ��ŵ�ջ��(��ջ)

void StackPop(Stack* st);//ɾ��ջ�����ݣ���ջ��

STDataType StackTop(Stack* st);//��ȡջ������

size_t StackSize(Stack* st);//��ȡջ����ЧԪ�ظ���

bool StackEmpty(Stack* st);//���ջ�Ƿ�Ϊ�գ�Ϊ�շ��ط�0�������Ϊ�շ���0
