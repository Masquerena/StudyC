#include "SListNode.h"

void SListPrint(SListNode* phead)//���ݴ�ӡ
{
	assert(phead);

	SListNode* tmp = phead;
	while (phead)
	{
		printf("%d ", phead->data);

		phead = phead->next;
	}
	printf("\n");
}

SListNode* SListFind(SListNode* phead, SLDataType x)//��������
{
	assert(phead);

	SListNode* tmp = phead;
	while (tmp)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

SListNode* BuySListNode(SLDataType x)//��̬����ռ�
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushFront(SListNode** pphead, SLDataType x)//��ͷ����������
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SListPushBack(SListNode** pphead, SLDataType x)//��β����������
{
	assert(pphead);

	SListNode* newnode = BuySListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SListNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x)//��posλ��֮ǰ����
{
	assert(*pphead);
	assert(pos);

	SListNode* cur = *pphead;
	if (cur != pos)
	{
		while (cur)
		{
			
			if (cur->next == pos)
			{
				SListNode* newnode = BuySListNode(x);

				cur->next = newnode;
				newnode->next = pos;
				break;
			}
			cur = cur->next;
		}
	}
	else
	{
		SListPushFront(pphead, x);
	}
	assert(cur);
}

void SListInsertAfter(SListNode** pphead, SListNode* pos, SLDataType x)//��posλ��֮�����
{
	assert(*pphead);
	assert(pos);

	SListNode* cur = *pphead;
	while (cur)
	{
		if (cur == pos)
		{
			SListNode* newnode = BuySListNode(x);
			SListNode* rem = cur->next;

			cur->next = newnode;
			newnode->next = rem;
			break;
		}
		cur = cur->next;
	}
	assert(cur);
}

void SListPopFront(SListNode** pphead)//��ͷ��ɾ������
{
	assert(*pphead);

	SListNode* del = *pphead;
	*pphead = (* pphead)->next;
	free(del);
	del = NULL;
}

void SListPopBack(SListNode** pphead)//��β��ɾ������
{
	assert(*pphead);

	SListNode* cur = NULL;
	SListNode* del = *pphead;
	while (del->next)
	{
		cur = del;
		del = del->next;
	}
	free(del);
	del = NULL;
	cur->next = NULL;
}

void SListPop(SListNode** pphead, SListNode* pos)//ɾ��posλ������
{
	assert(*pphead);
	assert(pos);

	SListNode* cur = NULL;
	SListNode* del = *pphead;
	while (del)
	{
		if (del == pos)
		{
			if (cur == NULL)
			{
				*pphead = (*pphead)->next;
				free(del);
				del = NULL;
				break;
			}

			cur->next = pos->next;
			free(del);
			del = NULL;
			break;
		}
		cur = del;
		del = del->next;
	}
}

void SListDistory(SListNode** pphead)//����������
{
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pphead = NULL;
}