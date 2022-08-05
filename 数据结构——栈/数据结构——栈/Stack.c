#include "Stack.h"

void StackInit(Stack* st)//���ݳ�ʼ��
{
	assert(st);

	st->a = NULL;
	st->top = st->capacity = 0;	
}

void StackDistory(Stack* st)//��������
{
	assert(st);

	free(st->a);
	st->a = NULL;
	st->top = st->capacity = 0;
}

void StackPrint(Stack* st)//���ݴ�ӡ
{
	int i = 0;
	while (i < st->top)
	{
		printf("%d ", st->a[i]);
		++i;
	}
	printf("\n");
}

void StackPush(Stack* st, STDataType x)//ջ��β��(��ջ)
{
	assert(st);

	if (st->top == st->capacity)
	{
		int newcapacity = (st->capacity == 0) ? 4 : 2 * st->capacity;
		STDataType* tmp = (STDataType*)realloc(st->a, newcapacity * sizeof(STDataType));

		if (tmp == NULL)
		{
			perror("realloc fail");
		}

		st->a = tmp;
		st->capacity = newcapacity;
	}

	st->a[st->top] = x;
	st->top++;
}

void StackPop(Stack* st)//ɾ��ջ�����ݣ���ջ��
{
	assert(st);
	assert(!StackEmpty(st));

	st->top--;
}

STDataType StackTop(Stack* st)//��ȡջ������
{
	assert(st);
	assert(!StackEmpty(st));

	return st->a[st->top - 1];
}

size_t StackSize(Stack* st)//��ȡջ����ЧԪ�ظ���
{
	assert(st);

	return st->top;
}

bool StackEmpty(Stack* st)//���ջ�������Ƿ�Ϊ�գ�Ϊ�շ��ط�0�������Ϊ�շ���0
{
	assert(st);

	return st->top == 0;
}