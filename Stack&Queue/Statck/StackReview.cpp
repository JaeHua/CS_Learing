#include<iostream>
using namespace std;
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;		//ջ��ָ��
}SqStack;
//ջ�ĳ�ʼ��
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;//����ջ��
}
//ջ������
void DestroyStack(SqStack*& s)
{
	free(s);
}
//ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s)
{
	return(s->top == -1);
}
//��ջ
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, ElemType e)
{
	if (s->top == -1)
		return 0;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
