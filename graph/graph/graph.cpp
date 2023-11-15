#include<iostream>
using namespace std;
const int MAXV = 500;
#define INF 100000
typedef int InfoType;
typedef struct ANode
{
	int adjvex;		//该边的邻接点编号
	struct ANode* nextarc;	//指向下一条边的指针
	int weight;			//该边的权值信息
}ArcNode;			//边结点的信息
typedef struct Vnode
{
	InfoType info;		//顶点的其他信息
	ArcNode* firstarc;	//指向第一个边结点
}VNode;
typedef struct
{
	VNode adjlist[MAXV];	//邻接表
	int n, e;			//图中的顶点数n和边数e
}AdjGraph;				//完整的图邻接表类型
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < n; i++)			//给邻接表中所有的头节点的指针域置初值
		G->adjlist[i].firstarc = NULL;
	for (int i = 0; i < n; i++)
		for (j = n - 1; j >= 0; j--)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));	//
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	G->n = n; G->e = e;
}
//输出邻接表
void DispAdj(AdjGraph* G)
{
	int i; ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d", i);
		while (p!= NULL)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}
//销毁图
void DestroyAdj(AdjGraph*& G)
{
	int i; ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)		//扫描所有的单链表
	{
		pre = G->adjlist[i].firstarc;		//p指向第i个单链表的所有边结点
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p; p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}
int main() {
	return 0;
}