#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct linknode
{
	ElemType data;	//������
	struct linknode* next;//ָ����
}LinkStNode;
//��ʼ��ջ
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//����ջ
void DestroyStack(LinkStNode*& s)
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}
//��ջ
void Push(LinkStNode*& s, ElemType e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));//��Ҫ���ǿ��ٿռ�
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//��ջ
bool Pop(LinkStNode*& s, ElemType& e)
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
}
//ȡջ��Ԫ��
bool GetTop(LinkStNode* s, ElemType& e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}
bool Match(ElemType exp[], int n)
{
	int i = 0;
	ElemType e;
	bool match = 1;
	LinkStNode* st;
	InitStack(st);
	while (i < n && match)
	{		if (exp[i] == '(')
			Push(st, exp[i]);
		else if (exp[i] == ')')
		{		if (GetTop(st, e))
			{			if (e != '(')
					match = false;
			else
				Pop(st, e);
			} 
			else
				match = false;
		}
		i++;
	}
	if (!StackEmpty(st))
		match = false;
	DestroyStack(st);
	return match;
}
int main()
{
	ElemType chs1[] = "(())";
	ElemType chs2[] = "(()))";
	if (Match(chs1, 4))
		cout << "ƥ��" << endl;
	else
		cout << "��ƥ��" << endl;
	if (Match(chs2, 5))
		cout << "ƥ��" << endl;
	else
		cout << "��ƥ��" << endl;
	return 0;
}