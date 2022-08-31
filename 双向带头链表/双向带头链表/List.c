#include "List.h"

ListNode* ListCreate()//创建哨兵位头节点
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

void ListPirnt(ListNode* head)//数据打印
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

ListNode* BuyListNode(LDataType x)//开辟空间
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

ListNode* ListFind(ListNode* head, LDataType x)//数据查找
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

void ListPushFront(ListNode* head, LDataType x)//从头部插入数据
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

void ListPushBack(ListNode* head, LDataType x)//从尾部插入数据
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

void ListPushInsert(ListNode* head, ListNode* pos, LDataType x)//在pos位置之前插入
{
	assert(head);
	assert(pos);

	ListNode* cur = BuyListNode(x);

	pos->perv->next = cur;
	cur->next = pos;
	cur->perv = pos->perv;
	pos->perv = cur;
}

void ListPushAfter(ListNode* head, ListNode* pos, LDataType x)//在pos位置之后插入
{
	assert(head);
	assert(pos);

	ListNode* cur = BuyListNode(x);

	cur->next = pos->next;
	pos->next->perv = cur;
	pos->next = cur;
	cur->perv = pos;
}

void ListPopFront(ListNode* head)//从头部删除数据
{
	assert(head);
	assert(head->next != head);

	ListNode* del = head->next;

	head->next->next->perv = head;
	head->next = head->next->next;
	
	free(del);
	del = NULL;
}

void ListPopBack(ListNode* head)//从尾部删除数据
{
	assert(head);
	assert(head->next != head);

	ListNode* del = head->perv;

	head->perv->perv->next = head;
	head->perv = head->perv->perv;

	free(del);
	del = NULL;
}

void ListErase(ListNode* pos)//删除pos位置的数据
{
	assert(pos);

	pos->perv->next = pos->next;
	pos->next->perv = pos->perv;

	free(pos);
	pos = NULL;
}

void ListDistory(ListNode* head)//空间销毁
{
	assert(head);

	ListNode* dis = head->next;
	while (dis != head)
	{
		ListNode* next = dis->next;
		free(dis);
		dis = next;
	}

	free(head);       //此处传的是一级指针，在此处使head = NULL；是没有效果的，需要二级指针
	head->next = NULL;//为保持接口的一致性，此处传的是一级指针，head的置空需要使用者自行置空
	head->perv = NULL;
	head->data = 0;
}