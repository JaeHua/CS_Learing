#include<iostream>
using namespace std;
const int MAXV = 500;
#define INF 100000
typedef int InfoType;
typedef struct ANode
{
	int adjvex;		//�ñߵ��ڽӵ���
	struct ANode* nextarc;	//ָ����һ���ߵ�ָ��
	int weight;			//�ñߵ�Ȩֵ��Ϣ
}ArcNode;			//�߽�����Ϣ
typedef struct Vnode
{
	InfoType info;		//�����������Ϣ
	ArcNode* firstarc;	//ָ���һ���߽��
}VNode;
typedef struct
{
	VNode adjlist[MAXV];	//�ڽӱ�
	int n, e;			//ͼ�еĶ�����n�ͱ���e
}AdjGraph;				//������ͼ�ڽӱ�����
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	int i, j; ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < n; i++)			//���ڽӱ������е�ͷ�ڵ��ָ�����ó�ֵ
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
//����ڽӱ�
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
//����ͼ
void DestroyAdj(AdjGraph*& G)
{
	int i; ArcNode* pre, * p;
	for (i = 0; i < G->n; i++)		//ɨ�����еĵ�����
	{
		pre = G->adjlist[i].firstarc;		//pָ���i������������б߽��
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