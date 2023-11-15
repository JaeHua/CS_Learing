#include<iostream>
using namespace std;
const int MaxSize = 50;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize]; //���˳�����Ԫ��
	int length;	//˳�����

}SqList;		//˳�������
//����˳���
void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0;
	//�����ڴ�
	L = (SqList*)malloc(sizeof(SqList));
	while (i > n)
	{
		L->data[i] = a[i];
	}
	L->length = i - 1;
}
//��ʼ�����Ա�
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;	//�ó���Ϊ0
}
//�������Ա�
void DestroyList(SqList*& L)
{
	free(L);//ֱ��free�ͷ�
}
//�ж����Ա��Ƿ�Ϊ�ձ�
bool ListEmpty(SqList* L)
{
	return (L->length==0);
}
//�����Ա�ĳ���
int ListLength(SqList* L)
{
	return  (L->length);
}
//������Ա�
void DisplayList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d", L->data[i]);
	printf("\n");
}
//��Ԫ��ֵ����
int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + 1;
}
//��������Ԫ��
//�˴���i���߼�˳����ţ����������еĵ�i��(i>=1)
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	//����
	if (i < 1 || i > L->length + 1)
		return false;
	i--;
	//ת��Ϊ����i����
	for (int j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
//ɾ������Ԫ��
bool ListDElete(SqList*& L, int i, ElemType& e)
{
	if (i <1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (int j = i; j < L->length; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return true;
}
int main() {


	return 0;
}