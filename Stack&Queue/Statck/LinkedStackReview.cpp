#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct linknode
{
	ElemType data;	//Êı¾İÓò
	struct linknode* next;//Ö¸ÕëÓò
}LinkStNode;
//³õÊ¼»¯Õ»
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//Ïú»ÙÕ»
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
//ÅĞ¶ÏÕ»ÊÇ·ñÎª¿Õ
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}
//³öÕ»
bool Pop(LinkStNode*& s, ElemType& e)
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
}
//È¡Õ»¶¥ÔªËØ
bool GetTop(LinkStNode* s, ElemType& e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}
int main()
{

	return 0;
}