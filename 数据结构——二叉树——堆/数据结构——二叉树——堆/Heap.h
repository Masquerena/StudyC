#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* data;//数据存储空间
	int size;//数据个数
	int capacity;//数据存储容量
}Heap;

void HeapInit(Heap* php);//数据初始化

void HeapPrint(Heap* php);//数据打印

void HAdjustUp(HDataType* data, int child);//向上调整法(仅适用于二叉树）

void HeapPush(Heap* php, HDataType x);//插入数据

void HeapJustDown(HDataType* data, int pose, int parent);//向下调整法(仅适用于二叉树）

void HeapPop(Heap* php);//删除堆顶数据

HDataType HeapTop(Heap* php);//获取堆顶数据

int HeapSize(Heap* php);//获取堆中元素个数

bool HeapEmpty(Heap* php);//判断堆中是否为空

void HeapDistory(Heap* php);//数据销毁

void PrintHeapK(Heap* php, int child, int k);//找出前n个最大或最小的数

void HeapRestore(Heap* php);//堆在使用PrintHeapK之后如需要还原堆可使用