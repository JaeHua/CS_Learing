#include<iostream>
using namespace std;
typedef int ElemType;
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
//����
void DestroyQueue(LinkQueue *&q)
{
	DataNode * pre = q->front,*p;	//preָ����׽�� 
	if(pre!=NULL)
	{
		p = pre->next;				//pָ����pre�ĺ�̽�� 
		while(p!=NULL)				//p����ѭ�� 
		{
			free(pre);				//�ͷ�pre��� 
			pre = p;				//ͬ������ 
			p = p->next;
		}
		free(pre);
	}
	free(q);
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
bool deQueue(LinkQuNode*& q, ElemType e)
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

	return 0;
}
