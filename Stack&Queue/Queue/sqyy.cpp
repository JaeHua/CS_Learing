#include<iostream>
using namespace std;
typedef int ElemType;
#define MaxSiaze 50
typedef struct
{
	ElemType data[MaxSiaze];
	int front, rear;	//队头与队尾指针
}SqQueue;
//初始化队列
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//销毁队列
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
//判断队列是否为空
bool QueueEmpty(SqQueue*& q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType e)
{
	if (q->rear == MaxSiaze - 1)	//队满上溢出
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)//队空下溢出
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
void number(int n)
{
	ElemType e;
	SqQueue* q;	
	InitQueue(q);	///切记初始化
	for (int i = 1; i <= n; i++)
	{
		enQueue(q, i);
	}
	while (!QueueEmpty(q))
	{
		deQueue(q, e);
		printf("%d,", e);
		if (!QueueEmpty(q))
		{
			deQueue(q, e); ///第二个直接出队再入队就是在最后了
			enQueue(q, e);
		}
	}
	DestroyQueue(q);	///销毁链队
}
int main() {

	int n = 8;
	number(n);

	return 0;
}