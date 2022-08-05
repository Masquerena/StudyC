#include "Stack.h"

STTest()
{
	Stack st;
	StackInit(&st);//测试数据初始化

	StackPush(&st, 1);//测试数据入栈
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPrint(&st);

	StackPop(&st);//测试数据出栈
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);

	STDataType test = StackTop(&st);//测试获取栈顶数据
	printf("%d\n", test);

	size_t sz = StackSize(&st);//测试获取栈中元素个数
	printf("%d\n", sz);
}

int main(void)
{
	STTest();
	return 0;
}