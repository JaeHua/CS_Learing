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
bool QueueEmpty(SqQueue*&q)
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
int main() {
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

	return 0;
}