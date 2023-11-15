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
	//创建头结点 
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
	//创建头结点
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;						//r始终指向尾结点，初始时指向头结点
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//重新分配空间
		s->data = a[i];
		r->next = s;
		r = s;
	}
	//尾结点的nextt域置为NULL
	r->next = NULL;			
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
	while (p!=NULL)
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
	if (i <= 0)//由于头结点的序号是0
		return false;
	while (p != NULL&&j<i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//不存在此结点，返回false
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
	while(p!=NULL&&p->data!=e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}

bool ListInsert(LinkNode*& L, int i, ElemType e)
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)return false;//首结点的次序是一
	while (j < i - 1 && p != NULL)//找到第i-1个结点
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		//典中典
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
	else {
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
void delmaxnode(LinkNode*& L)
{
	LinkNode* p = L->next, * pre = L, * maxp = p, * maxpre = pre;
	//用p扫描整个单链表，pre始终指向其前驱结点
	while (p != NULL)
	{
		if (maxp->data < p->data)
		{
			maxp = p;
			maxpre = pre;
		}
		//p,pre同步后移
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	//记得删除后释放
	free(maxp);
}

// 使用插入排序算法对链表进行排序
void sortList(LinkNode* &L) {
	LinkNode* p, * pre, * q;
	p = L->next->next;		//p指向L的第二个数据结点
	L->next->next = NULL;
	/*第一次执行插入操作时，我们需要将第一个节点插入到已排序链表的末尾。
	如果我们没有将L->next->next置为NULL，那么第一个节点的next指针仍然指向
	下一个需要排序的节点，导致新的已排序链表不完整。

*/
	while (p != NULL)
	{
		q = p->next;		//q保存p的后继结点
		pre = L;			//从有序单链表的开头进行比较，pre指向插入结点的前驱结点
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
int main()
{
	LinkNode* L;
	int a[10] = { 7,5,3,6,2,1,0,9,8,4 };
	CreatListR(L, a,10);
	DispList(L);
	sortList(L);
	DispList(L);
	return 0;
}
