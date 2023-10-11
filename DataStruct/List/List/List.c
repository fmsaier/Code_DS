#include "List.h"

//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType data;
//	struct ListNode* next;
//	struct ListNode* prev;
//}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	ListNode* prev = pHead;
	while (cur != pHead)
	{
		prev = cur->next;
		free(cur);
		cur = prev;
	}
	free(pHead);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	if (pHead->next = pHead)
	{
		printf("NULL");
		return;
	}
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	tail->next = newnode;
	newnode->data = x;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* tail = pHead->prev;
	ListNode* prev = tail->prev;
	prev->next = pHead;
	pHead->prev = prev;
	free(tail);
	tail = NULL;
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = cur;
	newnode->data = x;
	newnode->prev = pHead;
	cur->prev = newnode;
	pHead->next = newnode;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* cur = pHead->next;
	ListNode* next = cur->next;
	pHead->next = next;
	next->prev = pHead;
	free(cur);
	cur = NULL;
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* cur = pos->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = pos;
	pos->prev = newnode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos->next != pos);
	ListNode* cur = pos->prev;
	ListNode* next = pos->next;
	cur->next = pos->next;
	next->prev = cur;
	free(pos);
}