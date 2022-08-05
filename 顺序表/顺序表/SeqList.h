#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLdatatype;

typedef struct SeqList
{
	SLdatatype* a;//ָ�򿪱ٵĿռ�
	int size;//�ռ�洢��Ԫ�ظ���
	int capacity;//�ռ������
}SL;

void SLInit(SL* sl);//���ݳ�ʼ��

void SLdistory(SL* sl);//��������

void SLPrint(SL* sl);//���ݴ�ӡ

void SLCheckCapcity(SL* sl);//���˳�������

void SLPushFront(SL* sl);//��ͷ����������

void SLPushBack(SL* sl);//��β����������

void SLPopFront(SL* sl);//ɾ��ͷ������

void SLPopBack(SL* sl);//ɾ��β������

int SLFind(SL* sl, SLdatatype x);//����˳����е�ָ�����ݣ������±�

void SLInsert(SL* sl, size_t pos, SLdatatype x);//��ָ��λ�ò�������

void SLErase(SL* sl, size_t pos);//ɾ��ָ��λ������