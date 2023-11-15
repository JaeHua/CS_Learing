#include<iostream>
using  namespace std;
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;	//ջ��ָ��
}SqStack;
//ջ�ĳ�ʼ��
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;//ջ��ָ����-1
}
//ջ������
void DestroyStack(SqStack*& s)
{
	free(s);
}
//ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s)
{

	return (s->top == -1);
}
//��ջ
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)//ջ��
		return false;
	s->top++;	//ջ��ָ����һ
	s->data[s->top] = e; //Ԫ��e����ջ��ָ�봦
	return true;
}
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];//ȡջ��Ԫ��
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

int main() {
	SqStack* s;
	ElemType e;
	//1����ʼ��ջ
	InitStack(s);
	//2���ж�ջ�ǿ�
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ�ǿ�" << endl;
	//3����ջ
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	//4\�ж�ջ�ǿ�
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ�ǿ�" << endl;
	//5�������ջ����
	while(!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c ", e);
	}
	printf("\n");
	//��\�ж�ջ�ǿ�
	if (StackEmpty(s))
		cout << "ջΪ��" << endl;
	else
		cout << "ջ�ǿ�" << endl;
	//7���ͷ�ջ
	DestroyStack(s);

	return 0;
}