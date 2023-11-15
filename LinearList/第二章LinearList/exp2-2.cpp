#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct LinkNode
{
	ElemType data;		//存放元素值
	struct LinkNode* next;	//指向后继结点

}LinkNode;
void CreatListR(LinkNode*& L,int n,ElemType a[])
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
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
bool ListInsert(LinkNode*& L, int i, ElemType e)
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)return false;
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
bool ListEmpty(LinkNode*L)
{
	return (L->next == NULL);
}
int ListLength(LinkNode* L)
{
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)return false;
	while (j < i && p->next != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}
int LocateElem(LinkNode*L, ElemType e)
{
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL & p->data != e)
	{
		i++;
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
bool ListDelete(LinkNode*& L, int i,ElemType&e)
{
	int j = 0;
	LinkNode* p = L, * q;
	if(i<=0)return false;
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
		p->next = q->next;
		free(q);
		return true;
	}
}
//销毁线性表
void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
int main() {
	LinkNode* L;
	InitList(L);
	ElemType e;
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	printf("输出单链表:\n");
	DispList(L);
	printf("单链表长度:\n");
	cout << ListLength(L) << endl;
	printf("单链表是否为空:\n");
	cout << ListEmpty(L) << endl;
	GetElem(L, 3, e);
	printf("链表第三个元素是:\n%c\n",e);
	printf("元素a的位置是:\n%d\n", LocateElem(L, 'a'));
	ListInsert(L, 4, 'f');
	DispList(L);
	ListDelete(L, 3, e);
	DispList(L);
	DestroyList(L);
	return 0;
	
}