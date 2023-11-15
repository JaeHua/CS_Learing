#include<iostream>
using  namespace std;
#define MaxSize 50
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;	//’ª∂•÷∏’Î
}SqStack;
//’ªµƒ≥ı ºªØ
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;//’ª∂•÷∏’Î÷√-1
}
//’ªµƒœ˙ªŸ
void DestroyStack(SqStack*& s)
{
	free(s);
}
//’ª «∑ÒŒ™ø’
bool StackEmpty(SqStack* s)
{

	return (s->top == -1);
}
//Ω¯’ª
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)//’ª¬˙
		return false;
	s->top++;	//’ª∂•÷∏’Î‘ˆ“ª
	s->data[s->top] = e; //‘™Àÿe∑≈‘⁄’ª∂•÷∏’Î¥¶
	return true;
}
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];//»°’ª∂•‘™Àÿ
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
	//1°¢≥ı ºªØ’ª
	InitStack(s);
	//2°¢≈–∂œ’ª∑«ø’
	if (StackEmpty(s))
		cout << "’ªŒ™ø’" << endl;
	else
		cout << "’ª∑«ø’" << endl;
	//3°¢Ω¯’ª
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	Push(s, 'd');
	//4\≈–∂œ’ª∑«ø’
	if (StackEmpty(s))
		cout << "’ªŒ™ø’" << endl;
	else
		cout << "’ª∑«ø’" << endl;
	//5°¢ ‰≥ˆ≥ˆ’ª–Ú¡–
	while(!StackEmpty(s))
	{
		Pop(s,e);
		printf("%c ", e);
	}
	printf("\n");
	//¡˘\≈–∂œ’ª∑«ø’
	if (StackEmpty(s))
		cout << "’ªŒ™ø’" << endl;
	else
		cout << "’ª∑«ø’" << endl;
	//7°¢ Õ∑≈’ª
	DestroyStack(s);

	return 0;
}