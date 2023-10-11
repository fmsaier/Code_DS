#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Stack.h"
//��ӡ����
void PrintArr(int* a, int n);

//����
void Swap(int* a, int* b);

// ��������
void InsertSort(int* a, int n);

// ϣ������
void ShellSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

// ѡ������
void SelectSort(int* a, int n);

// ������
void AdjustDwon(int* a, int n, int parent);
void HeapSort(int* a, int n);

// ��������ݹ�ʵ��
// // ����ȡ��
int SearchMid(int* a, int left, int right);
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);

// ��������
void CountSort(int* a, int n);