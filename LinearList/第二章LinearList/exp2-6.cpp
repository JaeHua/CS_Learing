#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct LinkNode
{
	ElemType data;		//���Ԫ��ֵ
	struct LinkNode* next;	//ָ���̽��

}LinkNode;

//����������
void CreatListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;	//ͷ���ָ������NULL
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//���·���ռ�
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
void CreatListR(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	r = L;									//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//���·���ռ�
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;				//β����nextt����ΪNULL
}
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}
void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;	//preָ��p��ǰ�����
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);		//ѭ������ʱpΪNULL��preָ��β���
}
int ListLength(LinkNode* L)
{
	int n = 0;
	LinkNode* p = L;//pָ��ͷ���
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}void DispList(LinkNode* L)
{
	LinkNode* p = L->next;//ָ��ͷ���
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
	L->next = NULL;//��L��Ϊһ���ձ�
	r = L;
	while (p != NULL)
	{
		if (p->data < e)
		{
			q = p->next;
			p->next = L->next;
			L->next = p;
			if (p->next == NULL)//��p�ǵ�һ���ڿ�ͷ����Ľ�㣬����Ϊβ���
				r = p;
			p = q;
		}
		else
		{
			r->next = p;	//��p�����ڻ����x������뵽ĩβ
			r = p;
			p = p->next;
		}
	}
	r->next = NULL;
} // ���һ�Դ��������޸�����
int main()
{
	LinkNode* L;
	InitList(L);
	int x;
	ElemType e, a[10] = { 7,5,1,2,3,9,4,6,8,0 };
	CreatListR(L, a, 10);
	cout << "�����뻮�ֵı�׼X��" << endl;
	cin >> x;
	OrderList(L, x);
	DispList(L);
	return 0;
}
