#include "Queue.h"

void QueueInit(Queue* qn)//初始化队列
{
	assert(qn);

	qn->head = NULL;
	qn->tail = NULL;
}

void QueueDistory(Queue* qn)//销毁队列
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

void QueuePrint(Queue* qn)//数据打印
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

void QueuePush(Queue* qn, QEDataType x)//从尾部向队列插入数据(入队列)
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

void QueuePop(Queue* qn)//从头部删除队列数据（出队列）
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

QEDataType QueueFront(Queue* qn)//获取队列头部数据
{
	assert(qn);
	assert(!QueueEmpty(qn));

	return qn->head->data;
}

QEDataType QueueBack(Queue* qn)//获取队列尾部数据
{
	assert(qn);
	assert(!QueueEmpty(qn));

	return qn->tail->data;
}

int QueueSize(Queue* qn)//获取队列中的元素个数
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

int QueueEmpty(Queue* qn)//判断队列是否为空，为空返回非0值，非空则返回0
{
	assert(qn);

	return qn->head == NULL && qn->tail == NULL;
}