#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void Test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);

	QueuePop(&q);

	QueuePrint(&q);
	printf("\n");

	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);
}
int main()
{
	Test1();
	return 0;
}