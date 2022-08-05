#include"SeqList.h"
void SLInit(SL* sl)//���ݳ�ʼ��
{
	sl->a = NULL;
	sl->size = sl->capacity = 0;
}

void SLdistory(SL* sl)//��������
{
	free(sl->a);
	sl->a = NULL;
	sl->size = sl->capacity = 0;
}

void SLPrint(SL* sl)//��ӡ����
{
	int i = 0;
	for (i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->a[i]);
	}
	printf("\n");
}

void SLCheckCapcity(SL* sl)////���˳�������
{
	if (sl->size == sl->capacity)//���Ԫ�ظ�����ռ������Ƿ���ȣ����������
	{
		int newcapcity = (sl->capacity == 0) ? 4 : (2 * sl->capacity);//�жϿռ��Ƿ�Ϊ0��Ϊ0�򸳳�ʼֵ4����Ϊ0��Ϊ2��
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

void SLPushFront(SL* sl, SLdatatype x)//��ͷ����������
{
	assert(sl);

	SLCheckCapcity(sl);

	int i = sl->size;
	while (i)//����������Ų��һλ
	{
		sl->a[i] = sl->a[i - 1];
		i--;
	}
	sl->a[i] = x;
	sl->size++;
}

void SLPushBack(SL* sl, SLdatatype x)//��β����������
{
	assert(sl);

	SLCheckCapcity(sl);

	sl->a[sl->size] = x;
	sl->size++;
}

void SLPopFront(SL* sl)//ɾ��ͷ������
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

void SLPopBack(SL* sl)//ɾ��β������
{
	assert(sl);
	assert(sl->size != 0);

	sl->size--;
}

int SLFind(SL* sl, SLdatatype x)//����˳����е�ָ�����ݣ������±�
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

void SLInsert(SL* sl, size_t pos, SLdatatype x)//��ָ��λ�ò�������
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

void SLErase(SL* sl, size_t pos)//ɾ��ָ��λ������
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