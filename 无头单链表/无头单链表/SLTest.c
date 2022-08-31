#include "SListNode.h"

SLTest1()
{
	SListNode* test = NULL;

	SListPushFront(&test, 1);//ͷ�庯������
	SListPushFront(&test, 2);
	SListPushFront(&test, 3);
	SListPushFront(&test, 4);
	SListPrint(test);

	SListPushBack(&test, 5);//β�庯������
	SListPushBack(&test, 6);
	SListPushBack(&test, 7);
	SListPushBack(&test, 8);
	SListPrint(test);

	SListNode* test1 = SListFind(test, 4);//���Һ�������
	if (test1 == NULL)
	{
		printf("fail\n");
	}
	else
	printf("%d\n", test1->data);

	SListNode* test2 = SListFind(test, 4);
	SListInsert(&test, test2, 30);//��posλ��֮ǰ���뺯������
	SListPrint(test);

	SListNode* test3 = SListFind(test, 8);
	SListInsertAfter(&test, test3, 40);//��posλ��֮����뺯������
	SListPrint(test);

	SListPopFront(&test);//��ͷ��ɾ�����ݺ�������
	SListPopFront(&test);
	SListPopFront(&test);
	SListPrint(test);

	SListPopBack(&test);//��β��ɾ�����ݺ�������
	SListPopBack(&test);
	SListPrint(test);

	SListNode* test4 = SListFind(test, 5);//��posλ��ɾ����������
	SListPop(&test, test4);
	SListPrint(test);

	SListDistory(&test);//ɾ������������
	SListPrint(test);
}


int main(void)
{
	SLTest1();
	return 0;
}