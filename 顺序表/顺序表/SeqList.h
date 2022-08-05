#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLdatatype;

typedef struct SeqList
{
	SLdatatype* a;//指向开辟的空间
	int size;//空间存储的元素个数
	int capacity;//空间的容量
}SL;

void SLInit(SL* sl);//数据初始化

void SLdistory(SL* sl);//数据销毁

void SLPrint(SL* sl);//数据打印

void SLCheckCapcity(SL* sl);//检查顺序表容量

void SLPushFront(SL* sl);//在头部插入数据

void SLPushBack(SL* sl);//在尾部插入数据

void SLPopFront(SL* sl);//删除头部数据

void SLPopBack(SL* sl);//删除尾部数据

int SLFind(SL* sl, SLdatatype x);//查找顺序表中的指定数据，返回下标

void SLInsert(SL* sl, size_t pos, SLdatatype x);//在指定位置插入数据

void SLErase(SL* sl, size_t pos);//删除指定位置数据