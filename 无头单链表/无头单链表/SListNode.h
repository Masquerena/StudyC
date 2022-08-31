#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SListNode;

void SListPrint(SListNode* phead);//���ݴ�ӡ

SListNode* SListFind(SListNode* phead, SLDataType x);//��������

SListNode* BuySListNode(SLDataType x);//��̬����ռ�

void SListPushFront(SListNode** pphead, SLDataType x);//��ͷ����������

void SListPushBack(SListNode** pphead, SLDataType x);//��β����������

void SListInsert(SListNode** phead, SListNode* pos, SLDataType x);//��posλ��֮ǰ����

void SListInsertAfter(SListNode** pphead, SListNode* pos, SLDataType x);//��posλ��֮�����

void SListPopFront(SListNode** pphead);//��ͷ��ɾ������

void SListPopBack(SListNode** pphead);//��β��ɾ������

void SListPop(SListNode** pphead, SListNode* pos);//ɾ��posλ������

void SListDistory(SListNode* phead);//����������