#include "List.h"

//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType data;
//	struct ListNode* next;
//	struct ListNode* prev;
//}ListNode;

// 创建返回链表的头结点.
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
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
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
// 双向链表尾删
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
// 双向链表头插
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
// 双向链表头删
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
// 双向链表查找
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
// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
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