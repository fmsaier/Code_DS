#include "Queue.h"

//typedef int QDataType;
//typedef struct QListNode
//{
//	struct QListNode* next;
//	QDataType data;
//}QNode;
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* front;
//	QNode* rear;
//}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = data;
	newnode->next = NULL;
	if (q->front == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}
// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	QNode* cur = q->front->next;
	free(q->front);
	q->front = cur;
	if (q->front == NULL)
		q->rear = NULL;
}
//打印
void QueuePrint(Queue* q)
{
	assert(q);
	if (q->front == NULL)
	{
		printf("NULL");
		return;
	}
	QNode* cur = q->front;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	int size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		cur = q->front->next;
		free(q->front);
		q->front = cur;
	}
}