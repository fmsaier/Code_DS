#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
//typedef int HPDataType;
//typedef struct Heap
//{
//	HPDataType* a;
//	int size;
//	int capacity;
//}Heap;
// С����
//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	int tmp = 0;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
//���µ���
void AdjustDown(HPDataType* a, int parent, int n)
{
	int child = parent * 2 + 1;
	int tmp = 0;
	while (child < n)
	{
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (int i = 0; i < n; i++)
	{
		hp->a[i] = a[i];
		AdjustUp(hp->a, i);
	}
	hp->capacity = hp->size = n;
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->a);
	hp->size = hp->capacity = 0;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	//assert(hp->a);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->a = tmp;
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	AdjustUp(hp->a, hp->size);
	hp->size++;
}
// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->a);
	assert(hp->size > 0);
	hp->a[0] = hp->a[hp->size - 1];
	hp->size--;
	AdjustDown(hp->a, 0, hp->size);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(hp->a);
	assert(hp->size > 0);
	return hp->a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->size == 0;
}
//TopK����
void CreateNDate()
{
	// ������
	int n = 10000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	Heap hp;
	hp.a = NULL;
	hp.size = hp.capacity = 0;
	FILE* pf = fopen("data.txt", "r");
	if (pf == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	int tmp = 0;
	while (k--)
	{
		fscanf(pf, "%d", &tmp);
		HeapPush(&hp, tmp);
	}
	while (~fscanf(pf, "%d", &tmp))
	{
		if (tmp > HeapTop(&hp))
		{
			hp.a[0] = tmp;
			AdjustDown(hp.a, 0, hp.size);
		}
	}
	fclose(pf);
	pf = NULL;
	for (int i = 0; i < hp.size; i++)
	{
		printf("%d ", hp.a[i]);
	}
}
//������
void HeapSort(int* a, int n)
{
	int tmp = 0;
	//���� С���ѹ����ݼ�
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}//O(N)
	//���ϵ�����O(N*logN)
	int end = n - 1;
	while (end--)
	{
		tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, 0, end);
	}
}