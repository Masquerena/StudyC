#include "Heap.h"

void HeapInit(Heap* php)//�ṹ���ʼ��
{
	php->data = NULL;
	php->size = php->capacity = 0;
}

void HeapPrint(Heap* php)//���ݴ�ӡ
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

void swap(HDataType* child, HDataType* parent)//���ݽ���
{
	HDataType cur = *child;
	*child = *parent;
	*parent = cur;
}

void HAdjustUp(HDataType* data, int child)//���ϵ�����(�������ڶ�������
{
	assert(data);

	int parent = (child - 1) / 2;

	while (data[child] < data[parent])//"<"��С�ѣ�">"�����,��Ҫ�޸�Ӧ��HAdjustDown����ע�ʹ�ͬʱ�޸�
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

void HeapPush(Heap* php, HDataType x)//��������
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

void HeapJustDown(HDataType* data, int pose, int parent)//���µ�����
{                                                 //����ʹ��ʱ��while�е�һ��if�ĵڶ�����>���͵ڶ���if�е�
	assert(data);                                  //��>�����ƣ���Ϊ��>��ʱ����ѣ���֮ΪС��

	int minchild = parent * 2 + 1;
	int maxchild = parent * 2 + 2;
	if (pose <= 2)
	{
		minchild = 0;
		maxchild = 1;
	}
	while (minchild < pose)
	{
		if (maxchild < pose && data[minchild] > data[maxchild])//�˴��ĵڶ�����>���������if�еġ�>��
		{                                                                //Ҫͬʱ�޸ģ��޸�ʱӦ��HAdjustUp�����е�
			swap(&minchild, &maxchild);                                  //ע�ʹ�ͬʱ�޸�
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

void HeapPop(Heap* php)//ɾ���Ѷ�����
{
	assert(php);
	assert(!HeapEmpty(php));

	swap(&php->data[0], &php->data[php->size - 1]);

	--php->size;

	HeapJustDown(php->data, php->size, 0);
}

HDataType HeapTop(Heap* php)//��ȡ�Ѷ�����
{
	assert(php);
	assert(!HeapEmpty(php));

	return php->data[0];
}

int HeapSize(Heap* php)//��ȡ����Ԫ�ظ���
{
	assert(php);

	return php->size;
}

bool HeapEmpty(Heap* php)//�ж϶����Ƿ�Ϊ��
{
	assert(php);
	return php->size == 0;
}

void HeapDistory(Heap* php)//��������
{
	assert(php);

	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
	free(php);
}

void PrintHeapK(Heap* php, int child, int k)//�ҳ�ǰn��������С����
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

void HeapRestore(Heap* php)//����ʹ��PrintHeapK֮������Ҫ��ԭ�ѿ�ʹ��
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