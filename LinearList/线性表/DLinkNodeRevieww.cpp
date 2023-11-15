#include<iostream>	
using namespace std;
typedef int ElemType;
// 定义DlinkNode结构体
struct DlinkNode {
    int data;           // 数据域
    DlinkNode* prior;   // 前驱指针
    DlinkNode* next;    // 后继指针
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
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建头结点
    r = L;          //r始终指向尾结点，开始时指向头结点
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