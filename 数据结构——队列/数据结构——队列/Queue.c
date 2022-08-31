#include "Queue.h"

void QueueInit(Queue* qn)//��ʼ������
{
	assert(qn);

	qn->head = NULL;
	qn->tail = NULL;
}

void QueueDistory(Queue* qn)//���ٶ���
{
	assert(qn);

	QNode* cur = qn->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}

	qn->head = qn->tail = NULL;
}

void QueuePrint(Queue* qn)//���ݴ�ӡ
{
	assert(qn);

	QNode* tmp = qn->head;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void QueuePush(Queue* qn, QEDataType x)//��β������в�������(�����)
{
	assert(qn);

	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	
	if (qn->head == NULL)
	{
		qn->head = qn->tail = tmp;
		qn->head->data = x;	
	}
	else
	{
		qn->tail->next = tmp;
		qn->tail = qn->tail->next;
		qn->tail->data = x;
	}	

	qn->tail->next = NULL;
}

void QueuePop(Queue* qn)//��ͷ��ɾ���������ݣ������У�
{
	assert(qn);
	assert(!QueueEmpty(qn));

	QNode* del = qn->head;

	qn->head = qn->head->next;
	if (qn->head == NULL)
	{
		qn->tail = qn->tail->next;
	}
	free(del);
	del = NULL;
}

QEDataType QueueFront(Queue* qn)//��ȡ����ͷ������
{
	assert(qn);
	assert(!QueueEmpty(qn));

	return qn->head->data;
}

QEDataType QueueBack(Queue* qn)//��ȡ����β������
{
	assert(qn);
	assert(!QueueEmpty(qn));

	return qn->tail->data;
}

int QueueSize(Queue* qn)//��ȡ�����е�Ԫ�ظ���
{
	assert(qn);

	int i = 0;
	QNode* sz = qn->head;
	while (sz)
	{
		++i;
		sz = sz->next;
	}
	return i;
}

int QueueEmpty(Queue* qn)//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ��ط�0ֵ���ǿ��򷵻�0
{
	assert(qn);

	return qn->head == NULL && qn->tail == NULL;
}