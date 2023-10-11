#include "Queue.h"

//typedef int QDataType;
//typedef struct QListNode
//{
//	struct QListNode* next;
//	QDataType data;
//}QNode;
//// ���еĽṹ 
//typedef struct Queue
//{
//	QNode* front;
//	QNode* rear;
//}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
// ��β����� 
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
// ��ͷ������ 
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
//��ӡ
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}
// ���ٶ��� 
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