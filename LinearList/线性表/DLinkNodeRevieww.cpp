#include<iostream>	
using namespace std;
typedef int ElemType;
// ����DlinkNode�ṹ��
struct DlinkNode {
    int data;           // ������
    DlinkNode* prior;   // ǰ��ָ��
    DlinkNode* next;    // ���ָ��
};
void CreateListF(DlinkNode* L, int n, ElemType a[])
{
    DlinkNode* s;
    L = (DlinkNode*)malloc(sizeof(DlinkNode));
    L->prior = L->next = NULL;  
    for (int i = 0; i < n; i++)
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode));
        s->data = a[i];
        s->next = L->next;
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}
void CreatListR(DlinkNode* L, int n, ElemType a[])
{
    DlinkNode* s, * r;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // ����ͷ���
    r = L;          //rʼ��ָ��β��㣬��ʼʱָ��ͷ���
    for (int i = 0; i < n; i++)
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}