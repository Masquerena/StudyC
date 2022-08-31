#include "List.h"

void ListTest()
{
	ListNode* test = ListCreate();//哨兵位头节点创建函数测试
	ListPushFront(test, 1);//头节点插入函数测试
	ListPushFront(test, 2);
	ListPushFront(test, 3);
	ListPushFront(test, 4);
	ListPirnt(test);//打印函数测试

	ListPushBack(test, 5);
	ListPushBack(test, 6);
	ListPushBack(test, 7);
	ListPushBack(test, 8);
	ListPirnt(test);

	ListNode* test1 = ListFind(test, 5);//查找函数测试
	if (test1 == NULL)//尾删或者头删函数有问题，最后两个数据时会一次尾删删除最后两个
	{
		printf("can't find");
	}
	else
		printf("%d\n", test1->data);

	ListNode* test2 = ListFind(test, 4);
	ListPushInsert(test, test2, 20);//在pos位置之前插入函数测试
	ListPirnt(test);

	ListNode* test3 = ListFind(test, 8);
	ListPushAfter(test, test, 200);//在pos位置之后插入函数测试
	ListPirnt(test);

	//ListPopFront(test);//从头部删除数据函数测试
	//ListPopFront(test);
	//ListPopFront(test);
	//ListPopFront(test);
	//ListPopFront(test);
	/*ListPirnt(test);*/

	//ListPopBack(test);//从尾部删除数据函数测试
	//ListPopBack(test);
	//ListPopBack(test);
	//ListPopBack(test);
	//ListPopBack(test);
	/*ListPirnt(test);*/

	ListNode* test4 = ListFind(test, 200);//删除pos位置函数测试
	ListErase(test4);
	ListPirnt(test);

	ListDistory(test);
	test = NULL;
}

int main(void)
{
	ListTest();
	return 0;
}