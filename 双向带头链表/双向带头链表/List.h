#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LDataType;
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
	struct ListNode* perv;
}ListNode;

ListNode* ListCreate();//创建哨兵位头节点

ListNode* BuyListNode(LDataType x);//开辟空间

void ListPirnt(ListNode* head);//数据打印

ListNode* ListFind(ListNode* head, LDataType x);//数据查找

void ListPushFront(ListNode* head, LDataType x);//从头部插入数据

void ListPushBack(ListNode* head, LDataType x);//从尾部插入数据\

void ListPushInsert(ListNode* head, ListNode* pos, LDataType x);//在pos位置之前插入

void ListPushAfter(ListNode* head, ListNode* pos, LDataType x);//在pos位置之后插入

void ListPopFront(ListNode* head);//从头部删除数据

void ListPopBack(ListNode* head);//从尾部删除数据

void ListErase(ListNode* pos);//删除pos位置的数据

void ListDistory(ListNode* head);//空间销毁
