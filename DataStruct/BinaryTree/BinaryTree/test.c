#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
void Test1()
{
	char* s = "ABD##E#H##CF##G##";
	int i = 0;
	BTNode* bt = BinaryTreeCreate(s, strlen(s), &i);
	BinaryTreePrevOrder(bt);
	printf("\n");
	BinaryTreeLevelOrder(bt);
	printf("%c ", BinaryTreeFind(bt, 'B')->data);
	Queue q;
	QueueInit(&q);
}
int main()
{
	Test1();
	return 0;
}