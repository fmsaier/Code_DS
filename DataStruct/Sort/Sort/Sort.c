#include "Sort.h"

//打印数组
void PrintArr(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//交换
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
// 希尔排序
void ShellSort(int* a, int n) 
{
	int gap = n;
	while (gap > 1)
	{
		//gap = gap / 2;
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchage = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchage = 0;
			}
		}
		if (exchage)
			break;
	}
}
// 选择排序
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int max = begin, min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[begin], &a[min]);
		if (begin == max)
			max = min;
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}
// 堆排序
//升序-大根堆
void AdjustDwon(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}
	//排序
	for (int i = 1; i < n ; i++)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDwon(a, n - i, 0);
	}
}
// 快速排序递归实现
// 三数取中
int SearchMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left])
	{
		if (a[left] > a[right])
			return left;
		else if (a[mid] > a[right])
			return right;
		else
			return mid;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
}
// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left<right && a[right]>=a[keyi])
		{
			right--;
		}
		while (left<right && a[left]<=a[keyi])
		{
			left++;
		}
		Swap(&a[right], &a[left]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[hole])
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= a[hole])
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int keyi = left;
	int now = left + 1, prev = left;
	while (now <= right)
	{
		if (a[now] < a[keyi])
		{
			Swap(&a[++prev], &a[now]);
		}
			now++;
	}
	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSort(int* a, int left, int right)
{
	int begin = left, end = right;
	if (begin >= end)
		return;

	//减少栈帧消耗优化
	if (end - begin + 1 < 10)
		InsertSort(a, end - begin + 1);

	//三数取中
	int midi = SearchMid(a, left, right);
	Swap(&a[midi], &a[left]);

	//int keyi = PartSort1(a, begin, end);
	//int keyi = PartSort2(a, begin, end);
	int keyi = PartSort3(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	int begin = 0, end = 0;
	StackInit(&st); 
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		begin = StackTop(&st);
		StackPop(&st);

		end = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort3(a, begin, end);

		
		if (end > keyi + 1)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
}
// 归并排序实现
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);
	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	if (begin1 > end1)
	{
		while (begin2 <= end2)
		{
			tmp[index++] = a[begin2++];
		}
	}
	else if (begin2 > end2)
	{
		while (begin1 <= end1)
		{
			tmp[index++] = a[begin1++];
		}
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (NULL == tmp)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int gap = 1;
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (NULL == tmp)
	{
		perror("malloc fail");
		exit(-1);
	}
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, begin2 = i + gap;
			int end1 = i + gap - 1, end2 = i + 2 * gap - 1;
			int index = i;
			//右边不存在，直接跳出
			if (begin2 >= n)
				break;
			//右边存在越界，调整
			if (end2 >= n)
				end2 = n - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}
			if (begin1 > end1)
			{
				while (begin2 <= end2)
				{
					tmp[index++] = a[begin2++];
				}
			}
			else if (begin2 > end2)
			{
				while (begin1 <= end1)
				{
					tmp[index++] = a[begin1++];
				}
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min + 1;
	int* tmp = (int*)calloc(range, sizeof(int));
	if (NULL == tmp)
	{
		perror("calloc fail");
		exit(-1);
	}
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(tmp);
	tmp = NULL;
}
