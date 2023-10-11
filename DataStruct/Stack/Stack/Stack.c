#include "Stack.h"

//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;       // 栈顶
//	int capacity;  // 容量 
//}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity * sizeof(STDataType));
		if (NULL == tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		//记得更新
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = data;
	ps->top++;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->a);
	assert(ps->top > 0);
	ps->top--;
}
//打印
void StackPrint(Stack* ps)
{
	assert(ps);
	assert(ps->a);
	int size = 0;
	while (size < ps->top)
	{
		printf("%d ", ps->a[size]);
		size++;
	}
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->a);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	assert(ps->a);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	//记得滞空
	ps->top = ps->capacity = 0;
}