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

ListNode* ListCreate();//�����ڱ�λͷ�ڵ�

ListNode* BuyListNode(LDataType x);//���ٿռ�

void ListPirnt(ListNode* head);//���ݴ�ӡ

ListNode* ListFind(ListNode* head, LDataType x);//���ݲ���

void ListPushFront(ListNode* head, LDataType x);//��ͷ����������

void ListPushBack(ListNode* head, LDataType x);//��β����������\

void ListPushInsert(ListNode* head, ListNode* pos, LDataType x);//��posλ��֮ǰ����

void ListPushAfter(ListNode* head, ListNode* pos, LDataType x);//��posλ��֮�����

void ListPopFront(ListNode* head);//��ͷ��ɾ������

void ListPopBack(ListNode* head);//��β��ɾ������

void ListErase(ListNode* pos);//ɾ��posλ�õ�����

void ListDistory(ListNode* head);//�ռ�����
