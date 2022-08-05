#include"SeqList.h"
void SLInit(SL* sl)//数据初始化
{
	sl->a = NULL;
	sl->size = sl->capacity = 0;
}

void SLdistory(SL* sl)//数据销毁
{
	free(sl->a);
	sl->a = NULL;
	sl->size = sl->capacity = 0;
}

void SLPrint(SL* sl)//打印数据
{
	int i = 0;
	for (i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->a[i]);
	}
	printf("\n");
}

void SLCheckCapcity(SL* sl)////检查顺序表容量
{
	if (sl->size == sl->capacity)//检查元素个数与空间容量是否相等，相等则扩容
	{
		int newcapcity = (sl->capacity == 0) ? 4 : (2 * sl->capacity);//判断空间是否为0。为0则赋初始值4，不为0则为2倍
		SLdatatype* tmp = (SLdatatype*)realloc(sl->a, newcapcity * sizeof(SLdatatype));

		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}

		sl->a = tmp;
		sl->capacity = newcapcity;
	}
}

void SLPushFront(SL* sl, SLdatatype x)//在头部插入数据
{
	assert(sl);

	SLCheckCapcity(sl);

	int i = sl->size;
	while (i)//将数据往后挪动一位
	{
		sl->a[i] = sl->a[i - 1];
		i--;
	}
	sl->a[i] = x;
	sl->size++;
}

void SLPushBack(SL* sl, SLdatatype x)//在尾部插入数据
{
	assert(sl);

	SLCheckCapcity(sl);

	sl->a[sl->size] = x;
	sl->size++;
}

void SLPopFront(SL* sl)//删除头部数据
{
	assert(sl);
	assert(sl->size != 0);

	int i = 0;
	for (i = 0; i < sl->size; i++)
	{
		sl->a[i] = sl->a[i + 1];
	}
	sl->size--;
}

void SLPopBack(SL* sl)//删除尾部数据
{
	assert(sl);
	assert(sl->size != 0);

	sl->size--;
}

int SLFind(SL* sl, SLdatatype x)//查找顺序表中的指定数据，返回下标
{
	assert(sl);

	int i = 0;
	while (i < sl->size)
	{
		if (sl->a[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}

void SLInsert(SL* sl, size_t pos, SLdatatype x)//在指定位置插入数据
{
	assert(sl);
	assert(pos <= sl->size);

	SLCheckCapcity(sl);

	int i = sl->size;
	while (i > pos)
	{
		sl->a[i] = sl->a[i - 1];
		--i;
	}
	sl->size++;
	sl->a[pos] = x;
}

void SLErase(SL* sl, size_t pos)//删除指定位置数据
{
	assert(sl);
	assert(pos <= sl->size);

	int i = 0;
	while (i < sl->size)
	{
		if (i == pos)
		{
			while (i < sl->size)
			{
				sl->a[i] = sl->a[i + 1];
				++i;
			}
		}
		++i;
	}
	sl->size--;
}