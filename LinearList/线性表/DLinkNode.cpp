#include<iostream>	
using namespace std;
typedef int ElemType;
// 定义DlinkNode结构体
struct DlinkNode {
    int data;           // 数据域
    DlinkNode* prior;   // 前驱指针
    DlinkNode* next;    // 后继指针
};
	
// 定义CreateListF函数
void CreateListF(DlinkNode*& L, ElemType a[], int n)
{
    DlinkNode* s;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建头结点
    L->prior = L->next = NULL; // 先后指针域置NULL
    for (int i = 0; i < n; i++) // 循环创建数据结点
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建数据结点s
        s->data = a[i];
        s->next = L->next; // 将S插到头结点之后
        if (L->next != NULL)
            L->next->prior = s;
        L->next = s;
        s->prior = L;
    }
}
void CreateListR(DlinkNode*& L, ElemType a[], int n)
{
    DlinkNode* s,*r;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建头结点
    r = L;          //r始终指向尾结点，开始时指向头结点
    for (int i = 0; i < n; i++) // 循环创建数据结点
    {
        s = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建数据结点s
        s->data = a[i];
        r->next = s; s->prior = r;      //将s结点插入到r结点之后
        r = s;                          //r指向尾结点
    }
    r->next = NULL;
}
