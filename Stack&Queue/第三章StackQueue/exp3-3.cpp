#include<iostream>
using namespace std;
typedef char ElemType;
#define MaxSiaze 50
typedef struct
{
	ElemType data[MaxSiaze];
	int front, rear;	//队头与队尾指针
}SqQueue;
//环形初始化队列
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
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
	if ((q->rear +1 )%MaxSiaze==q->front)	//队满上溢出
		return false;
	q->rear = (q->rear+1)%MaxSiaze;
	q->data[q->rear] = e;
	return true;
}
bool deQueue(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)//队空下溢出
		return false;
	q->front = (q->front+1)%MaxSiaze;
	e = q->data[q->front];
	return true;
}
int main() {
	SqQueue* q;
	ElemType e;
	//初始化
	InitQueue(q);
	//判断是否为空
	int c = QueueEmpty(q);
	cout << c << endl;
	//依次进队
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	//出队一个元素
	deQueue(q, e);
	cout << e << endl;
	//依次进队
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	//输出出队序列
	while (deQueue(q, e))
	{
		cout << e << endl;
	}
	free(q);
	return 0;
}