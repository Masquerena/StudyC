#include "Stack.h"

STTest()
{
	Stack st;
	StackInit(&st);//�������ݳ�ʼ��

	StackPush(&st, 1);//����������ջ
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);

	StackPop(&st);//�������ݳ�ջ
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);

	STDataType test = StackTop(&st);//���Ի�ȡջ������
	printf("%d\n", test);

	size_t sz = StackSize(&st);//���Ի�ȡջ��Ԫ�ظ���
	printf("%d\n", sz);
}

int main(void)
{
	STTest();
	return 0;
}