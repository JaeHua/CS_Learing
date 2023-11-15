#include<bits/stdc++.h>

using namespace std;
const int MaxSize = 50;
typedef char ElemType;
typedef struct BTNode {
	ElemType data;		//����Ԫ��
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//����������
void CreatBTree(BTNode*& b, char* str)
{
	BTNode* St[MaxSize], * p = NULL;	//St������Ϊ˳��ջ
	int top = -1, k, j = 0;		//topΪջ��ָ��
	char ch;
	b = NULL;					//��ʼʱ������Ϊ��
	ch = str[j];
	while (ch != '\0')			//ѭ��ɨ��str��ÿһ���ַ�
	{
		switch (ch)
		{
		case'(':top++; St[top] = p; k = 1; break;
		case')':top--; break;
		case',':k = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
//���ٶ�����
void DestroyBTree(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->lchild);
		free(b);
	}
}
//���ҽ��
BTNode* FindNode(BTNode* b, ElemType x)
{
	BTNode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = FindNode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(p->rchild, x);
	}
}
//�Һ��ӽ��
BTNode* LchildNode(BTNode* p)
{
	return p->lchild;
}
BTNode* RchildNode(BTNode* p)
{
	return p->rchild;
}
//��߶�
int BTHeight(BTNode* b)
{
	int lchildh, rchildh;
	if (b == NULL)return 0;
	else
	{
		lchildh = BTHeight(b->lchild);
		rchildh = BTHeight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
//���������
void DispBTree(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild != NULL)printf(",");
			DispBTree(b->rchild);
			printf(")");
		}
	}
}
void PreOrder(BTNode* b)
{
	if (b != NULL)
	{
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
void InOrder(BTNode* b)
{
	if (b != NULL)
	{
		PreOrder(b->lchild);
		printf("%c", b->data);
		PreOrder(b->rchild);
	}
}
void PostOrder(BTNode* b)
{
	if (b != NULL)
	{
		PreOrder(b->lchild);
		PreOrder(b->rchild);
		printf("%c", b->data);
	}
}

int main() {
	BTNode* b;
	char a[] = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	CreatBTree(b, a);
	DispBTree(b);
	cout << endl;
	PreOrder(b);
	cout << endl;
	InOrder(b);
	cout << endl;
	PostOrder(b);
	return  0;
}