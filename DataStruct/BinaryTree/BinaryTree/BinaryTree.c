#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType data;
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	if (*pi == n)
		return NULL;
	BTNode* tmp = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == tmp)
	{
		perror("malloc fail");
		exit(-1);
	}
	tmp->data = a[(*pi)++];
	tmp->left = BinaryTreeCreate(a, n, pi);
	tmp->right = BinaryTreeCreate(a, n, pi);
	return tmp;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* left = BinaryTreeFind(root->left, x);
	BTNode* right = BinaryTreeFind(root->right, x);
	return left == NULL ? right : left;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	BTNode* tmp;
	Queue q;
	QueueInit(&q);
	if (root);
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		tmp = QueueFront(&q);
		if (tmp->left != NULL)
			QueuePush(&q, tmp->left);
		if (tmp->right != NULL)
			QueuePush(&q, tmp->right);
		QueuePop(&q);
		printf("%c ", tmp->data);
	}
	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	BTNode* front = NULL;
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		front = QueueFront(&q);
		if (front == NULL)
			break;
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
		QueuePop(&q);	
	}
	while (!QueueEmpty(&q))
	{
		front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return 0;
		}
	}
	QueueDestroy(&q);
	return 1;
}