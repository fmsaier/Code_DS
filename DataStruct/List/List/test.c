#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void Test1()
{
	ListNode* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);

	ListPopBack(head);
	ListPopBack(head);
	ListPopBack(head);

	ListPushFront(head, 0);
	ListPushFront(head, -1);

	ListPopFront(head);

	ListPrint(head);

	ListDestory(head);
}
void Test2()
{
	ListNode* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);

	ListPrint(head);
	printf("\n");

	ListNode* cur = ListFind(head, 4);
	printf("%d ", cur->data);
	cur = ListFind(head, 6);
	if (cur == NULL)
		printf("NULL ");

	ListDestory(head);
}
void Test3()
{
	ListNode* head = ListCreate();

	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	
	ListInsert(ListFind(head, 1), 0);
	ListErase(ListFind(head, 1));
	ListErase(ListFind(head, 0));

	ListPrint(head);
	printf("\n");

	ListDestory(head);
}
int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}