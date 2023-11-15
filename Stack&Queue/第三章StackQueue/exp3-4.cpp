#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct qnode
{
	ElemType data;	//���Ԫ��
	struct qnode* next;//��һ�����ָ��
}DataNode;
typedef struct
{
	DataNode* front; //ָ����׽��
	DataNode* rear; //ָ����׽��
}LinkQuNode;
 //��ʼ��
void InitQueue(LinkQuNode*& q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
void DestroyQueue(LinkQuNode*& q)
{
	DataNode *p = q->front, * r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);
}
bool QueueEmpty(LinkQuNode* q)
{
	return(q->rear == NULL);
}

//������
void enQueue(LinkQuNode*& q,ElemType e)
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)//������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;	//�����p���ӵ���β������rearָ����
		q->rear = p;
	}
}
//������
bool deQueue(LinkQuNode*& q, ElemType &e)
{
	DataNode* t;
	if (q->rear == NULL)	//ԭ�������Ѿ�Ϊ��
		return false;
	t = q->front;			//ָ���׽��
	if (q->front == q->rear)	//ԭ��������ֻ��һ�����ݽ��
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
}
int main()
{
	LinkQuNode* q;
	ElemType e;
	//��ʼ������
	InitQueue(q);
	//�Ƿ�Ϊ��
	int c = QueueEmpty(q);
	cout << c << endl;
	//����
	enQueue(q, 'a');
	enQueue(q, 'b');
	enQueue(q, 'c');
	//����
	deQueue(q, e);
	cout << e << endl;
	//����
	enQueue(q, 'd');
	enQueue(q, 'e');
	enQueue(q, 'f');
	//���
	while (!QueueEmpty(q))
	{
		deQueue(q, e);
		cout << e << endl;
	}

	return 0;
}