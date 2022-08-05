#include"SeqList.h"

SLTest1()//初始化测试函数
{
	SL s;
	SLInit(&s);//测试数据初始化
	SLPushBack(&s, 1);//测试数据尾部输入
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPrint(&s);

	SLPushFront(&s, 10);//测试数据头部输入
	SLPushFront(&s, 20);
	SLPushFront(&s, 30);
	SLPushFront(&s, 40);
	SLPrint(&s);

	
	SLInsert(&s, 0, 100);//测试数据插入
	SLPrint(&s);

	SLErase(&s, 3);//测试删除指定位置数据
	SLPrint(&s);

	int i = SLFind(&s, 20);//测试查找
	printf("%d\n", s.a[i]);

	SLPopFront(&s);//测试数据头部删除
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPrint(&s);

	SLPopBack(&s);//测试数据尾部删除
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