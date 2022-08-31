#include "Heap.h"

void HeapInit(Heap* php)//结构体初始化
{
	php->data = NULL;
	php->size = php->capacity = 0;
}

void HeapPrint(Heap* php)//数据打印
{
	assert(php);
	assert(!HeapEmpty(php));

	int i = 0;
	while (i < php->size)
	{
		printf("%d ", php->data[i]);
		++i;
	}
	printf("\n");
}

void swap(HDataType* child, HDataType* parent)//数据交换
{
	HDataType cur = *child;
	*child = *parent;
	*parent = cur;
}

void HAdjustUp(HDataType* data, int child)//向上调整法(仅适用于二叉树）
{
	assert(data);

	int parent = (child - 1) / 2;

	while (data[child] < data[parent])//"<"建小堆，">"建大堆,若要修改应与HAdjustDown函数注释处同时修改
	{
		swap(&data[child], &data[parent]);

		child = parent;
		parent = (child - 1) / 2;

		if (child == 0)
		{
			break;
		}
	}
}

void HeapPush(Heap* php, HDataType x)//插入数据
{
	assert(php);

	if (php->size == php->capacity)
	{
		int newcapacity = (php->capacity == 0) ? 4 : 2 * php->capacity;
		HDataType* tmp = (HDataType*)realloc(php->data, newcapacity * sizeof(HDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->data = tmp;
		php->capacity = newcapacity;
	}

	php->data[php->size] = x;
	++php->size;

	int child = php->size - 1;
	HAdjustUp(php->data, child);
}

void HeapJustDown(HDataType* data, int pose, int parent)//向下调整法
{                                                 //单独使用时手while中第一个if的第二个“>”和第二个if中的
	assert(data);                                  //“>”控制，都为“>”时建大堆，反之为小堆

	int minchild = parent * 2 + 1;
	int maxchild = parent * 2 + 2;
	if (pose <= 2)
	{
		minchild = 0;
		maxchild = 1;
	}
	while (minchild < pose)
	{
		if (maxchild < pose && data[minchild] > data[maxchild])//此处的第二个“>”和下面的if中的“>”
		{                                                                //要同时修改，修改时应与HAdjustUp函数中的
			swap(&minchild, &maxchild);                                  //注释处同时修改
		} 

		if (data[parent] > data[minchild])
		{
			swap(&data[parent], &data[minchild]);
		}
		parent = minchild;
		minchild = parent * 2 + 1;
		maxchild = parent * 2 + 2;
	}
}

void HeapPop(Heap* php)//删除堆顶数据
{
	assert(php);
	assert(!HeapEmpty(php));

	swap(&php->data[0], &php->data[php->size - 1]);

	--php->size;

	HeapJustDown(php->data, php->size, 0);
}

HDataType HeapTop(Heap* php)//获取堆顶数据
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->data[0];
}

int HeapSize(Heap* php)//获取堆中元素个数
{
	assert(php);

	return php->size;
}

bool HeapEmpty(Heap* php)//判断堆中是否为空
{
	assert(php);
	return php->size == 0;
}

void HeapDistory(Heap* php)//数据销毁
{
	assert(php);

	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
	free(php);
}

void PrintHeapK(Heap* php, int child, int k)//找出前n个最大或最小的数
{
	assert(php);
	assert(!HeapEmpty(php));

	while (k && child)
	{
		printf("%d ", php->data[0]);
		swap(&php->data[0], &php->data[child]);
		HeapJustDown(php->data, child, 0);
		--k;
		--child;
	}
	printf("\n");
}

void HeapRestore(Heap* php)//堆在使用PrintHeapK之后如需要还原堆可使用
{
	assert(php);
	assert(!HeapEmpty(php));

	int i = 0;
	while (i < php->size)
	{
		HAdjustUp(php->data, i);
		i++;
	}
}