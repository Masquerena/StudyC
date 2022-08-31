#include "List.h"

ListNode* ListCreate()//�����ڱ�λͷ�ڵ�
{
	ListNode* guard = (ListNode*)malloc(sizeof(ListNode));
	if (guard == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	guard->next = guard;
	guard->perv = guard;
	guard->data = 0;

	return guard;
}

void ListPirnt(ListNode* head)//���ݴ�ӡ
{
	assert(head);

	ListNode* cur = head->next;

	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* BuyListNode(LDataType x)//���ٿռ�
{
	ListNode* newplace = (ListNode*)malloc(sizeof(ListNode));
	if (newplace == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newplace->data = x;
	newplace->next = NULL;
	newplace->perv = NULL;

	return newplace;
}

ListNode* ListFind(ListNode* head, LDataType x)//���ݲ���
{
	assert(head);

	ListNode* cur = head->next;
	while (cur != head && cur->data != x)
	{
		cur = cur->next;
	}
	if (cur == head)
	{
		perror("find fail");
		return NULL;
	}
	return cur;
}

void ListPushFront(ListNode* head, LDataType x)//��ͷ����������
{
	assert(head);

	ListNode* cur = BuyListNode(x);
	if (head->next == head)
	{
		head->next = cur;
		head->perv = cur;

		cur->next = head;
		cur->perv = head;
	}
	else
	{
		cur->next = head->next;
		head->next->perv = cur;
		cur->perv = head;
		head->next = cur;
	}
}

void ListPushBack(ListNode* head, LDataType x)//��β����������
{
	assert(head);

	ListNode* cur = BuyListNode(x);
	if (head->next == head)
	{
		head->next = cur;
		head->perv = cur;
		cur->next = head;
		cur->perv = head;
	}
	else
	{
		head->perv->next = cur;
		cur->next = head;
		cur->perv = head->perv;
		head->perv = cur;
	}
}

void ListPushInsert(ListNode* head, ListNode* pos, LDataType x)//��posλ��֮ǰ����
{
	assert(head);
	assert(pos);

	ListNode* cur = BuyListNode(x);

	pos->perv->next = cur;
	cur->next = pos;
	cur->perv = pos->perv;
	pos->perv = cur;
}

void ListPushAfter(ListNode* head, ListNode* pos, LDataType x)//��posλ��֮�����
{
	assert(head);
	assert(pos);

	ListNode* cur = BuyListNode(x);

	cur->next = pos->next;
	pos->next->perv = cur;
	pos->next = cur;
	cur->perv = pos;
}

void ListPopFront(ListNode* head)//��ͷ��ɾ������
{
	assert(head);
	assert(head->next != head);

	ListNode* del = head->next;

	head->next->next->perv = head;
	head->next = head->next->next;
	
	free(del);
	del = NULL;
}

void ListPopBack(ListNode* head)//��β��ɾ������
{
	assert(head);
	assert(head->next != head);

	ListNode* del = head->perv;

	head->perv->perv->next = head;
	head->perv = head->perv->perv;

	free(del);
	del = NULL;
}

void ListErase(ListNode* pos)//ɾ��posλ�õ�����
{
	assert(pos);

	pos->perv->next = pos->next;
	pos->next->perv = pos->perv;

	free(pos);
	pos = NULL;
}

void ListDistory(ListNode* head)//�ռ�����
{
	assert(head);

	ListNode* dis = head->next;
	while (dis != head)
	{
		ListNode* next = dis->next;
		free(dis);
		dis = next;
	}

	free(head);       //�˴�������һ��ָ�룬�ڴ˴�ʹhead = NULL����û��Ч���ģ���Ҫ����ָ��
	head->next = NULL;//Ϊ���ֽӿڵ�һ���ԣ��˴�������һ��ָ�룬head���ÿ���Ҫʹ���������ÿ�
	head->perv = NULL;
	head->data = 0;
}