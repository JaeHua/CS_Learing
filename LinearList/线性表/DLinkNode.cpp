#include<iostream>	
using namespace std;
typedef int ElemType;
// ����DlinkNode�ṹ��
struct DlinkNode {
    int data;           // ������
    DlinkNode* prior;   // ǰ��ָ��
    DlinkNode* next;    // ���ָ��
};
	
// ����CreateListF����
void CreateListF(DlinkNode*& L, ElemType a[], int n)
{
    DlinkNode* s;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // ����ͷ���
    L->prior = L->next = NULL; // �Ⱥ�ָ������NULL
    for (int i = 0; i < n; i++) // ѭ���������ݽ��
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode)); // �������ݽ��s
        s->data = a[i];
        s->next = L->next; // ��S�嵽ͷ���֮��
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}
void CreateListR(DlinkNode*& L, ElemType a[], int n)
{
    DlinkNode* s,*r;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // ����ͷ���
    r = L;          //rʼ��ָ��β��㣬��ʼʱָ��ͷ���
    for (int i = 0; i < n; i++) // ѭ���������ݽ��
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode)); // �������ݽ��s
        s->data = a[i];
        r->next = s; s->prior = r;      //��s�����뵽r���֮��
        r = s;                          //rָ��β���
    }
    r->next = NULL;
}
