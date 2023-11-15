#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct linknode
{
	ElemType data;	//数据域
	struct linknode* next;//指针域
}LinkStNode;
//初始化栈
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}
//销毁栈
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
//判断栈是否为空
bool StackEmpty(LinkStNode* s)
{
	return (s->next == NULL);
}
//进栈
void Push(LinkStNode*& s, ElemType e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));//不要忘记开辟空间
	p->data = e;
	p->next = s->next;
	s->next = p;
}
//出栈
bool Pop(LinkStNode*& s, ElemType& e)
{
	LinkStNode* p;
	if (s->next == NULL)
		return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
}
//取栈顶元素
bool GetTop(LinkStNode* s, ElemType& e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

int main()
{
	LinkStNode* s;
	ElemType e;
	InitStack(s);

	return 0;
}