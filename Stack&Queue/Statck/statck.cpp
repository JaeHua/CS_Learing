#include<iostream>
using  namespace std;
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;	//栈顶指针
}SqStack;
//栈的初始化
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;//栈顶指针置-1
}
//栈的销毁
void DestroyStack(SqStack*& s)
{
	free(s);
}
//栈是否为空
bool StackEmpty(SqStack* s)
{

	return (s->top == -1);
}
//进栈
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize -1)//栈满
		return false;
	s->top++;	//栈顶指针增一
	s->data[s->top] = e; //元素e放在栈顶指针处
	return true;
}
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];//取栈顶元素
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
bool symmetry(ElemType str[])
{
	ElemType e;
	SqStack* st;
	InitStack(st);
	for (int i = 0; str[i] != '\0'; i++)
		Push(st, str[i]);
	for (int i = 0; str[i] != '\0'; i++)
	{
		Pop(st,e);
		if (str[i] != e)
		{
			DestroyStack(st);
			return false;
		}
	}
	DestroyStack(st);
	return true;
}
int main() {
	SqStack* st;
	ElemType e;
	ElemType s[] = "abcba";
	if (symmetry(s))
		cout << s << "是回文串" << endl;
	else
	{
		cout << s << "不是回文串" << endl;
	}
	return 0;
}