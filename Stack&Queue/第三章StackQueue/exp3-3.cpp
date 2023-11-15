#include<iostream>
using namespace std;
typedef char ElemType;
#define MaxSiaze 50
typedef struct
{
	ElemType data[MaxSiaze];
	int front, rear;	//��ͷ���βָ��
}SqQueue;
//���γ�ʼ������
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
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
	if ((q->rear +1 )%MaxSiaze==q->front)	//���������
		return false;
	q->rear = (q->rear+1)%MaxSiaze;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)//�ӿ������
		return false;
	q->front = (q->front+1)%MaxSiaze;
	e = q->data[q->front];
	return true;
}
int main() {
	SqQueue* q;
	ElemType e;
	//��ʼ��
	InitQueue(q);
	//�ж��Ƿ�Ϊ��
	int c = QueueEmpty(q);
	cout << c << endl;
	//���ν���
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	//����һ��Ԫ��
	deQueue(q, e);
	cout << e << endl;
	//���ν���
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	//�����������
	while (deQueue(q, e))
	{
		cout << e << endl;
	}
	free(q);
	return 0;
}