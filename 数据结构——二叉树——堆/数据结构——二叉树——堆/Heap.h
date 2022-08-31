#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* data;//���ݴ洢�ռ�
	int size;//���ݸ���
	int capacity;//���ݴ洢����
}Heap;

void HeapInit(Heap* php);//���ݳ�ʼ��

void HeapPrint(Heap* php);//���ݴ�ӡ

void HAdjustUp(HDataType* data, int child);//���ϵ�����(�������ڶ�������

void HeapPush(Heap* php, HDataType x);//��������

void HeapJustDown(HDataType* data, int pose, int parent);//���µ�����(�������ڶ�������

void HeapPop(Heap* php);//ɾ���Ѷ�����

HDataType HeapTop(Heap* php);//��ȡ�Ѷ�����

int HeapSize(Heap* php);//��ȡ����Ԫ�ظ���

bool HeapEmpty(Heap* php);//�ж϶����Ƿ�Ϊ��

void HeapDistory(Heap* php);//��������

void PrintHeapK(Heap* php, int child, int k);//�ҳ�ǰn��������С����

void HeapRestore(Heap* php);//����ʹ��PrintHeapK֮������Ҫ��ԭ�ѿ�ʹ��