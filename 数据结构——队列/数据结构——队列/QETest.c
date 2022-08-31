#include "Queue.h"

QETist()
{
	Queue qe;
	QueueInit(&qe);

	QueuePush(&qe, 1);
	QueuePush(&qe, 2);
	QueuePush(&qe, 3);
	QueuePush(&qe, 4);
	QueuePrint(&qe);

	QueuePop(&qe);
	QueuePop(&qe);
	QueuePop(&qe);
	QueuePop(&qe);
	QueuePrint(&qe);

	QEDataType test = QueueFront(&qe);
	printf("%d\n", test);
	QEDataType test2 = QueueBack(&qe);
	printf("%d\n", test2);

	int num = QueueSize(&qe);
	printf("%d\n", num);
}
int main(void)
{
	QETist();
	return 0;
}