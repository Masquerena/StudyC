#include "Heap.h"

HeapTest()
{
	Heap test;
	HeapInit(&test);

	HeapPush(&test, 65);//插入数据函数测试
	HeapPush(&test, 100);
	HeapPush(&test, 70);
	HeapPush(&test, 32);
	HeapPush(&test, 50);
	HeapPush(&test, 40);
	HeapPush(&test, 80);
	HeapPush(&test, 37);
	HeapPush(&test, 51);
	HeapPush(&test, 97);
	HeapPush(&test, 55);
	HeapPrint(&test);

	PrintHeapK(&test, test.size - 1, 3);//返回最小或最大函数测试
	HeapPrint(&test);
	HeapRestore(&test);//堆还原函数测试
	HeapPrint(&test);

	HeapPop(&test);//删除数据函数测试
	HeapPrint(&test);

	HDataType test1 = HeapTop(&test);//返回堆顶数据函数测试
	printf("%d\n", test1);

	HeapPop(&test);
	HeapPrint(&test);

	test1 = HeapTop(&test);
	printf("%d\n", test1);

	test1 = HeapSize(&test);//返回堆中元素个数函数测试
	printf("%d\n", test1);
}

//HeapTest2(int* a, int n)
//{
//	
//	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//	{
//		HeapJustDown(a, n, i);
//	}
//}
int main(void)
{
	HeapTest();
	//int a[] = { 1, 7, 10, 6, 2 };
	//HeapTest2(&a, sizeof(a) / sizeof(a[0]));
	return 0;
}