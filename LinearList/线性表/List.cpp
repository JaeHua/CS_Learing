#include<iostream>
using namespace std;
const int MaxSize = 1005;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

//����˳���
void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	//�ǵ�һ��Ҫ�����ڴ�ռ� 
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
	return(L->length == 0);
}

int ListLength(SqList* L)
{
	return (L->length);
}
void DisplayList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d", L->data[i]);
	printf("\n");
}
bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i > L->length)
		return false;
	e = L->data[i - 1];
	return true;	//�ɹ��ҵ�Ԫ�ط���true
}
int LocateElem(SqList* L,ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
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
	//�����Ƿ���� 
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
void partitionl(SqList*& L)
{
	int i = 0, j = L->length - 1;
	ElemType pivot = L->data[0];
	while (i < j)
	{
		while (j > i && L->data[j] > pivot)
			j--;
		L->data[i] = L->data[j];
		while (i < j && L->data[i] <= pivot)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = pivot;
	}
void move_even_odd(SqList*& L)
{
	int i = 0, j = L->length - 1;
	while (i < j)
	{
		//�ҵ���һ������Ԫ��
		//���� 
		while (i < j && L->data[j] % 2 == 0)
			j--;
		while (i < j && L->data[i] % 2 == 1)
			i++;
		if (i < j)
			swap(L->data[i], L->data[j]);
	}
}
int main() {
	SqList* L;
	int a[10] = { 7,5,7,7,9,1,6,2,4,8 };
	CreateList(L, a, 10);
	
	/*
	move_even_odd(L);
	partitionl(L);
	delnodel(L, 7);
	*/
	DisplayList(L);
}
