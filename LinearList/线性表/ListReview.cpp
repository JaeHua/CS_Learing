#include<iostream>
using namespace std;
const int MaxSize = 50;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize]; //存放顺序表中元素
	int length;	//顺序表长度

}SqList;		//顺序表类型
//建立顺序表
void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0;
	//分配内存
	L = (SqList*)malloc(sizeof(SqList));
	while (i > n)
	{
		L->data[i] = a[i];
	}
	L->length = i - 1;
}
//初始化线性表
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;	//置长度为0
}
//销毁线性表
void DestroyList(SqList*& L)
{
	free(L);//直接free释放
}
//判断线性表是否为空表
bool ListEmpty(SqList* L)
{
	return (L->length==0);
}
//求线性表的长度
int ListLength(SqList* L)
{
	return  (L->length);
}
//输出线性表
void DisplayList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d", L->data[i]);
	printf("\n");
}
//按元素值查找
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
//插入数据元素
//此处的i是逻辑顺序符号，表述数组中的第i个(i>=1)
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	//特判
	if (i < 1 || i > L->length + 1)
		return false;
	i--;
	//转化为物理i符号
	for (int j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return true;
}
//删除数据元素
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