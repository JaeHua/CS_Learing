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
	//����ͷ��� 
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
	//����ͷ���
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;						//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//���·���ռ�
		s->data = a[i];
		r->next = s;
		r = s;
	}
	//β����nextt����ΪNULL
	r->next = NULL;			
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

bool ListEmpty(LinkNode* L)
{
	return(L->next == NULL);
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


}
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;//ָ��ͷ���
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
	if (i <= 0)//����ͷ���������0
		return false;
	while (p != NULL&&j<i)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)//�����ڴ˽�㣬����false
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
	if (i <= 0)return false;//�׽��Ĵ�����һ
	while (j < i - 1 && p != NULL)//�ҵ���i-1�����
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		//���е�
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
	if (i <= 0)return false;//ͷ����ǲ��������е�
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
	//��pɨ������������preʼ��ָ����ǰ�����
	while (p != NULL)
	{
		if (maxp->data < p->data)
		{
			maxp = p;
			maxpre = pre;
		}
		//p,preͬ������
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	//�ǵ�ɾ�����ͷ�
	free(maxp);
}

// ʹ�ò��������㷨�������������
void sortList(LinkNode* &L) {
	LinkNode* p, * pre, * q;
	p = L->next->next;		//pָ��L�ĵڶ������ݽ��
	L->next->next = NULL;
	/*��һ��ִ�в������ʱ��������Ҫ����һ���ڵ���뵽�����������ĩβ��
	�������û�н�L->next->next��ΪNULL����ô��һ���ڵ��nextָ����Ȼָ��
	��һ����Ҫ����Ľڵ㣬�����µ�����������������

*/
	while (p != NULL)
	{
		q = p->next;		//q����p�ĺ�̽��
		pre = L;			//����������Ŀ�ͷ���бȽϣ�preָ��������ǰ�����
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
