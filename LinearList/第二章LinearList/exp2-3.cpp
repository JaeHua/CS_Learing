#include<iostream>	
using namespace std;
typedef char ElemType;
// 定义DlinkNode结构体
struct DlinkNode {
    ElemType data;           // 数据域
    DlinkNode* prior;   // 前驱指针
    DlinkNode* next;    // 后继指针
};

// 定义CreateListF函数
void CreateListF(DlinkNode*& L, ElemType a[], int n)
{
    DlinkNode* s;
    L = (DlinkNode*)malloc(sizeof(DlinkNode)); // 创建头结点
    L->prior = NULL;
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
void InitList(DlinkNode*& L)
{
    L = (DlinkNode*)malloc(sizeof(DlinkNode));
    L->next = NULL;
}
bool DListInsert(DlinkNode*& L, int i, ElemType e)
{
    DlinkNode* p = L, * s;
    int j = 0;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL||j>i-1)
        return false;
    else
    {
        //注意给s开辟动态空间
        s = (DlinkNode*)malloc(sizeof(DlinkNode));
        s->data = e;
        s->next = p->next;
        if(p->next !=NULL)
            p->next->prior = s;
        s->prior = p;
        p->next = s;
        return true;
    }
}
void DispDList(DlinkNode* L)
{
    if (L == NULL || L->next == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    DlinkNode* p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int ListLength(DlinkNode* L)
{
    DlinkNode* p = L->next;
    int j = 0;
    while (p!=NULL)
    {
        j++;
        p = p->next;
    }
    return j;
}
bool ListEmpty(DlinkNode* L)
{
    return(L->next == NULL);
}
bool GetElem(DlinkNode* L, int i, ElemType& e)
{
    DlinkNode* p = L->next;
    int j = 1;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    else
    {
        e = p->data;
        return true;
    }
}
int LocatElem(DlinkNode* L,ElemType e)
{
    DlinkNode* p = L->next;
    int j = 1;
    while (p->data != e && p->next != NULL)
    {
        j++;
        p = p->next;
    }
    if (p->next == NULL)
        return false;
    return j;
}
bool ListDelete(DlinkNode*& L, int i, ElemType& e)
{
    DlinkNode* p = L, * s;
    int j = 0;
    if (i <= 0)
        return false;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }
    if (p == NULL || p->next == NULL)
        return false;
    else
    {
        s = p->next;
        e = s->data;
        p->next = s->next;
        if (s->next != NULL)
            s->next->prior = p;
        free(s);
        return true;
    }
}
void DestroyList(DlinkNode*& L)
{
    DlinkNode* p = L, * q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L = NULL;
}
int main() {
    DlinkNode* L;
    ElemType e;
    InitList(L);
    cout << "输出双链表：" << endl;
    DListInsert(L, 1, 'a');
    DListInsert(L, 2, 'b');
    DListInsert(L, 3, 'c');
    DListInsert(L, 4, 'd');
    DListInsert(L, 5, 'e');
    DispDList(L);
    printf("双链表的长度是:\n%d", ListLength(L));
    printf("双链表是否为空:\n%d", ListEmpty(L));
    if (GetElem(L, 3, e))
        printf("双链表第三个元素是:\n%c", e);
    else
        printf("第三个元素不存在\n");
    printf("双链表的a元素位置是:\n%d\n", LocatElem(L,'a'));
    DListInsert(L, 4, 'f');
    DispDList(L);
    ListDelete(L, 3,e);
    DispDList(L);
    DestroyList(L);
	return 0;
}