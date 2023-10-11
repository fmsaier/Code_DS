#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
void Test1()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	/*StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);*/

	StackPop(&st);
	StackPop(&st);

	/*StackPrint(&st);
	printf("\n");

	printf("%d\n", StackTop(&st));
	printf("%d\n", StackSize(&st));*/
	printf("%d\n", StackEmpty(&st));

	StackDestroy(&st);
}
bool isValid(char* s) {
	int i = 0;
	char tmp = 0;
	Stack s1;
	StackInit(&s1);
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			StackPush(&s1, s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (StackEmpty(&s1))
				return false;
			tmp = StackTop(&s1);
			StackPop(&s1);
			if ((tmp == '(' && s[i] != ')')
				|| (tmp == '[' && s[i] != ']')
				|| (tmp == '{' && s[i] != '}'))
			{
				//printf("2");
				return false;
			}

		}
	}
	if (!StackEmpty(&s1))
		return false;

	return true;
}
int main()
{
	Test1();
	return 0;
}