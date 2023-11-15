#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct qnode
{
	ElemType data;	//存放元素
	struct qnode* next;//下一个结点指针
}DataNode;
typedef struct
{
	DataNode* front; //指向队首结点
	DataNode* rear; //指向队首结点
}LinkQuNode;
 //初始化
void InitQueue(LinkQuNode*& q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//销毁
void DestroyQueue(LinkQueue *&q)
{
	DataNode * pre = q->front,*p;	//pre指向队首结点 
	if(pre!=NULL)
	{
		p = pre->next;				//p指向结点pre的后继结点 
		while(p!=NULL)				//p不空循环 
		{
			free(pre);				//释放pre结点 
			pre = p;				//同步后移 
			p = p->next;
		}
		free(pre);
	}
	free(q);
} 
//进队列
void enQueue(LinkQuNode*& q,ElemType e)
{
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)//若链队为空，则新结点既是队首结点又是队尾结点
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;	//将结点p链接到队尾，并将rear指向它
		q->rear = p;
	}
}
//出队列
bool deQueue(LinkQuNode*& q, ElemType e)
{
	DataNode* t;
	if (q->rear == NULL)	//原来队列已经为空
		return false;
	t = q->front;			//指向首结点
	if (q->front == q->rear)	//原来队列中只有一个数据结点
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
