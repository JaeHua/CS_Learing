#include<iostream>
using namespace std;
typedef struct snode {
	char data;
	struct snode* next;
}LinkStrNode;
//尾插法建立链串
void StrAssign(LinkStrNode*& s, char cstr[])
{
	int i;
	LinkStrNode* r, * p;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;
	for (i = 0; cstr[i] != '\0'; i++)
	{
		p = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
//销毁串
void DestroyStr(LinkStrNode*&s)
{
	LinkStrNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
}
void StrCopy(LinkStrNode*& s, LinkStrNode* t)
{
	LinkStrNode* p = t->next, * q, * r;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
}
//判断串相等
bool StrEqual(LinkStrNode* s, LinkStrNode* t)
{
	LinkStrNode* p = s->next, * q = t->next;
	while (p != NULL && q != NULL && p->data == q->data)
	{
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL)
		return true;
	return false;
}
//求串长
int StrLength(LinkStrNode* s)
{
	int  i = 0;
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
//串的连接
LinkStrNode* contact(LinkStrNode * s, LinkStrNode * t)
{
	LinkStrNode* str, * p = s->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = str;
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = p;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return  str;
}
//求子串
LinkStrNode* SubStr(LinkStrNode* s, int i, int j)
{
	int k;
	LinkStrNode* str, * p = s->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;
	for (k = 1; k < i; k++)
		p = p->next;
	for (k = 1; k <= j; k++)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return NULL;
}
//子串插入
LinkStrNode* InsStr(LinkStrNode* s, int i, LinkStrNode* t)
{
	int k;
	LinkStrNode* str, * p = s->next, * pl = t->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLength(s) + 1)
		return str;
	for (k = 1; k < i; k++) //置结果串str为空串//:指向结果串的尾结点//参数不正确时返回空申//将s的前i个结点复制到str 
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	while (pl!=NULL) { 
	//将t的所有结点复制到str 
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = pl->data;
		r->next = q; r = q;
		pl = pl->next;
	}
	while (p != NULL) {
		//将t的所有结点复制到str 
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
}
//字串删除
LinkStrNode* DelStr(LinkStrNode* s, int i, int j)
{
	int k;
	LinkStrNode* str, * p = s->next,*q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s));
	return str;
	for (int k = 1; k < i; k++)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}
//子串的替换
LinkStrNode* RepStr (LinkStrNode* s, int i, int j, LinkStrNode* t)
{
	int k;
	LinkStrNode* str, * p = s->next, * p1 = t->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;
	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;
	for (int k = 0; k < i - 1; k++)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while(p1 !=NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p1->data; aa222q->next = NULL;
		r->next = q; r = q;
		p1 = p1->next;
	}
	while (p != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}
//输出串
void DispStr(LinkStrNode* s)
{
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {

	return 0;
}