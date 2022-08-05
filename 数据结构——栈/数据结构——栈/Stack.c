#include "Stack.h"

void StackInit(Stack* st)//数据初始化
{
	assert(st);

	st->a = NULL;
	st->top = st->capacity = 0;	
}

void StackDistory(Stack* st)//数据销毁
{
	assert(st);

	free(st->a);
	st->a = NULL;
	st->top = st->capacity = 0;
}

void StackPrint(Stack* st)//数据打印
{
	int i = 0;
	while (i < st->top)
	{
		printf("%d ", st->a[i]);
		++i;
	}
	printf("\n");
}

void StackPush(Stack* st, STDataType x)//栈的尾插(入栈)
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

void StackPop(Stack* st)//删除栈顶数据（出栈）
{
	assert(st);
	assert(!StackEmpty(st));

	st->top--;
}

STDataType StackTop(Stack* st)//获取栈顶数据
{
	assert(st);
	assert(!StackEmpty(st));

	return st->a[st->top - 1];
}

size_t StackSize(Stack* st)//获取栈中有效元素个数
{
	assert(st);

	return st->top;
}

bool StackEmpty(Stack* st)//检测栈内数据是否为空，为空返回非0结果，不为空返回0
{
	assert(st);

	return st->top == 0;
}