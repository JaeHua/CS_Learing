#include<iostream>
using namespace std;
const int MaxSize = 1005;
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

//����˳���
void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++; i++;
	}
	L->length = k;
}
//��ʼ�����Ա�
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0; //�ÿ����Ա�ĳ���Ϊ0
}
void DestroyList(SqList*& L)
{
	free(L);//�ͷ�L��ָ��˳���ռ�
}
bool ListEmpty(SqList* L)
{
	return (L->length == 0);
}

int ListLength(SqList* L)
{
	return (L->length);
}
void DisplayList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%c", L->data[i]);
	printf("\n");
}
bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i > L->length)
		return false;
	e = L->data[i - 1];
	return true;	//�ɹ��ҵ�Ԫ�ط���true
}
int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length&& L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;		//�����߼����
}
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i < 1 || i >L->length + 1 || L->length == MaxSize)
		return false;
	i--;
	for (j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
bool ListDelete(SqList*& L, int i, ElemType& e)
{
	int j;
	if (i < 1 || i>L->length)
		return false;
	i--;
	for (int j = i; j < L->length - 1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}
void delnodel(SqList*& L, ElemType x)
{
	int k = 0;
	for (int i = 0; i < L->length; i++)
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}
int main() {
	//task1
	SqList* L;
	InitList(L);
	//task2
	ListInsert(L, 1, 'a');
	ListInsert(L, 2, 'b');
	ListInsert(L, 3, 'c');
	ListInsert(L, 4, 'd');
	ListInsert(L, 5, 'e');
	//task3
	cout << "˳����е�Ԫ���ǣ�" << endl;
	DisplayList(L);
	//task4
	cout << "˳���ĳ����ǣ�" << endl;
	cout << ListLength(L) << endl;;
	//task5
	cout << "˳����Ƿ�Ϊ��:" << endl;
	cout << ListEmpty(L) << endl;;
	//task6
	cout << "˳���ĵ�����Ԫ����:" << endl;
	ElemType e;
	cout << GetElem(L, 3,e)<<endl;
	//task7
	cout << "Ԫ��a��λ����:" << endl;
	cout << LocateElem(L, 'a')<<endl;
	//task8
	ListInsert(L, 4, 'f');
	//task9
	DisplayList(L);
	//tsk10
	ElemType ee = ListDelete(L, 3, e);
	//task11
	DisplayList(L);
	//task12
	DestroyList(L);
}