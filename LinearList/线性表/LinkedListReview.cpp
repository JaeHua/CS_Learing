#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;		//存放元素值
	struct LNode* next; //指向后继结点
}LinkNode;				//单链表结点类型
void CreatListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));//创建头节点
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
void CreatListR(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
void DestoryList(LinkNode*& L)
{
	LinkNode* s =L, *p = L->next;
	while (p != NULL)
	{
		free(s);
		s = p;
		p = s->next;
	}
	free(s);
}
bool ListEmpty(LinkNode* L)
{
	return(L->next == NULL);
}

int ListLength(LinkNode* L)
{
	int n = 0;
	LinkNode* p = L;//p指向头结点
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;//指向头结点
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	int j = 0;
	LinkNode* p = L->next;
	if (i <= 0)
		return false;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}
int locateElem(LinkNode* L, ElemType e)
{
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
bool ListInsert(LinkNode*& L, ElemType e, int i)
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
bool ListDelete(LinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0)return false;//头结点是不计入其中的
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next; free(q);
		return true;
	}
}
int main()
{

	return 0;
}