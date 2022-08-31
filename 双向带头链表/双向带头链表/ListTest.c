#include "List.h"

void ListTest()
{
	ListNode* test = ListCreate();//�ڱ�λͷ�ڵ㴴����������
	ListPushFront(test, 1);//ͷ�ڵ���뺯������
	ListPushFront(test, 2);
	ListPushFront(test, 3);
	ListPushFront(test, 4);
	ListPirnt(test);//��ӡ��������

	ListPushBack(test, 5);
	ListPushBack(test, 6);
	ListPushBack(test, 7);
	ListPushBack(test, 8);
	ListPirnt(test);

	ListNode* test1 = ListFind(test, 5);//���Һ�������
	if (test1 == NULL)//βɾ����ͷɾ���������⣬�����������ʱ��һ��βɾɾ���������
	{
		printf("can't find");
	}
	else
		printf("%d\n", test1->data);

	ListNode* test2 = ListFind(test, 4);
	ListPushInsert(test, test2, 20);//��posλ��֮ǰ���뺯������
	ListPirnt(test);

	ListNode* test3 = ListFind(test, 8);
	ListPushAfter(test, test, 200);//��posλ��֮����뺯������
	ListPirnt(test);

	//ListPopFront(test);//��ͷ��ɾ�����ݺ�������
	//ListPopFront(test);
	//ListPopFront(test);
	//ListPopFront(test);
	//ListPopFront(test);
	/*ListPirnt(test);*/

	//ListPopBack(test);//��β��ɾ�����ݺ�������
	//ListPopBack(test);
	//ListPopBack(test);
	//ListPopBack(test);
	//ListPopBack(test);
	/*ListPirnt(test);*/

	ListNode* test4 = ListFind(test, 200);//ɾ��posλ�ú�������
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