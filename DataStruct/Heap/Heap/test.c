#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Test1()
{
	Heap hp;
	int a[] = { 6,9,4,2,4,3,8,3 };
	HeapCreate(&hp, a, sizeof(a) / sizeof(HPDataType));
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.a[i]);
	}
	printf("\n");
	HeapPop(&hp);
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.a[i]);
	}

}
void Test2()
{
	//CreateNDate();
	PrintTopK(10);
}
void Test3()
{
	int a[] = { 5,9,3,4,8,19,2,4,3,4 };
	HeapSort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}