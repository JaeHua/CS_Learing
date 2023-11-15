#include<iostream>
using namespace std;
typedef int ElemType;
#define MaxSiaze 50
typedef struct
{
	ElemType data[MaxSiaze];
	int front, rear;	//��ͷ���βָ��
}SqQueue;
//��ʼ������
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}
//���ٶ���
void DestroyQueue(SqQueue*& q)
{
	free(q);
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue*& q)
{
	return(q->front == q->rear);
}
bool enQueue(SqQueue*& q, ElemType e)
{
	if (q->rear == MaxSiaze - 1)	//���������
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)//�ӿ������
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}
void number(int n)
{
	ElemType e;
	SqQueue* q;	
	InitQueue(q);	///�мǳ�ʼ��
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
			deQueue(q, e); ///�ڶ���ֱ�ӳ�������Ӿ����������
			enQueue(q, e);
		}
	}
	DestroyQueue(q);	///��������
}
int main() {

	int n = 8;
	number(n);

	return 0;
}