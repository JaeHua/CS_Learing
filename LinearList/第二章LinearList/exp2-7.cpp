#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode {
    ElemType data;
    struct LinkNode* next;
} LinkNode;

// 创建单链表
void CreateList(LinkNode*& L, ElemType a[], int n) {
    L = new LinkNode;
    L->next = NULL;
    for (int i = n - 1; i >= 0; i--) {
        LinkNode* p = new LinkNode;
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

// 遍历单链表
void TraverseList(LinkNode* L) {
    LinkNode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 将 L1 和 L2 合并为 L3
void merge(LinkNode* L1, LinkNode* L2, LinkNode* L3) {
    LinkNode* p = L1->next, * q = L2->next, * r;
    L3->next = NULL;
    r = L3;
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
        }
        else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    r->next = (p != NULL) ? p : q;
}

int main() {
    LinkNode* L1, * L2, * L3;
    ElemType a1[] = { 1, 3, 5 };
    ElemType a2[] = { 2, 4, 6 };
    CreateList(L1, a1, 3);
    CreateList(L2, a2, 3);
    CreateList(L3, NULL, 0);

    cout << "L1: ";
    TraverseList(L1);
    cout << "L2: ";
    TraverseList(L2);

    merge(L1, L2, L3);
    cout << "L1 after merge: ";
    TraverseList(L1);

    return 0;
}