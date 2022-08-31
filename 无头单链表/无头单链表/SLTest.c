#include "SListNode.h"

SLTest1()
{
	SListNode* test = NULL;

	SListPushFront(&test, 1);//头插函数测试
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPrint(test);

	SListPushBack(&test, 5);//尾插函数测试
	SListPushBack(&test, 6);
	SListPushBack(&test, 7);
	SListPushBack(&test, 8);
	SListPrint(test);

	SListNode* test1 = SListFind(test, 4);//查找函数测试
	if (test1 == NULL)
	{
		printf("fail\n");
	}
	else
	printf("%d\n", test1->data);

	SListNode* test2 = SListFind(test, 4);
	SListInsert(&test, test2, 30);//在pos位置之前插入函数测试
	SListPrint(test);

	SListNode* test3 = SListFind(test, 8);
	SListInsertAfter(&test, test3, 40);//在pos位置之后插入函数测试
	SListPrint(test);

	SListPopFront(&test);//从头部删除数据函数测试
	SListPopFront(&test);
	SListPopFront(&test);
	SListPrint(test);

	SListPopBack(&test);//从尾部删除数据函数测试
	SListPopBack(&test);
	SListPrint(test);

	SListNode* test4 = SListFind(test, 5);//从pos位置删除函数测试
	SListPop(&test, test4);
	SListPrint(test);

	SListDistory(&test);//删除链表函数测试
	SListPrint(test);
}


int main(void)
{
	SLTest1();
	return 0;
}