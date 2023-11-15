#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LinkNode
{
	ElemType data;		//存放元素值
	struct LinkNode* next;	//指向后继结点

}LinkNode;

//建立单链表
void CreatListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;	//头结点指针域置NULL
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//重新分配空间
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
void CreatListR(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));//创建头结点
	r = L;									//r始终指向尾结点，初始时指向头结点
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//重新分配空间
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;				//尾结点的nextt域置为NULL
}
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;	//pre指向p的前驱结点
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);		//循环结束时p为NULL，pre指向尾结点
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
}void DispList(LinkNode* L)
{
	LinkNode* p = L->next;//指向头结点
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
	printf("\n");
}
void OrderList(LinkNode*& L, ElemType e)
{
	LinkNode* p = L->next, * q, * r;
	L->next = NULL;//将L变为一个空表
	r = L;
	while (p != NULL)
	{
		if (p->data < e)
		{
			q = p->next;
			p->next = L->next;
			L->next = p;
			if (p->next == NULL)//若p是第一个在开头插入的结点，则其为尾结点
				r = p;
			p = q;
		}
		else
		{
			r->next = p;	//若p结点大于或等于x，则插入到末尾
			r = p;
			p = p->next;
		}
	}
	r->next = NULL;
} // 添加一对大括号来修复错误
int main()
{
	LinkNode* L;
	InitList(L);
	int x;
	ElemType e, a[10] = { 7,5,1,2,3,9,4,6,8,0 };
	CreatListR(L, a, 10);
	cout << "请输入划分的标准X：" << endl;
	cin >> x;
	OrderList(L, x);
	DispList(L);
	return 0;
}
