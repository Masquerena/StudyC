#include"SeqList.h"

SLTest1()//��ʼ�����Ժ���
{
	SL s;
	SLInit(&s);//�������ݳ�ʼ��
	SLPushBack(&s, 1);//��������β������
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPushFront(&s, 10);//��������ͷ������
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);
	SLPushFront(&s, 40);
	SLPrint(&s);

	
	SLInsert(&s, 0, 100);//�������ݲ���
	SLPrint(&s);

	SLErase(&s, 3);//����ɾ��ָ��λ������
	SLPrint(&s);

	int i = SLFind(&s, 20);//���Բ���
	printf("%d\n", s.a[i]);

	SLPopFront(&s);//��������ͷ��ɾ��
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopBack(&s);//��������β��ɾ��
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPrint(&s);
}


int main(void)
{
	SLTest1();
	return 0;
}