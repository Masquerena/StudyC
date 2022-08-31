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

void SListPrint(SListNode* phead);//数据打印

SListNode* SListFind(SListNode* phead, SLDataType x);//查找数据

SListNode* BuySListNode(SLDataType x);//动态申请空间

void SListPushFront(SListNode** pphead, SLDataType x);//从头部插入数据

void SListPushBack(SListNode** pphead, SLDataType x);//从尾部插入数据

void SListInsert(SListNode** phead, SListNode* pos, SLDataType x);//在pos位置之前插入

void SListInsertAfter(SListNode** pphead, SListNode* pos, SLDataType x);//在pos位置之后插入

void SListPopFront(SListNode** pphead);//从头部删除数据

void SListPopBack(SListNode** pphead);//从尾部删除数据

void SListPop(SListNode** pphead, SListNode* pos);//删除pos位置数据

void SListDistory(SListNode* phead);//单链表销毁