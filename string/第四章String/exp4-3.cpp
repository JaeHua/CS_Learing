#include<iostream>
using namespace std;
const int MaxSize = 200;
typedef struct
{
	char data[MaxSize];
	int length;
}SqString; //存放串字符//存放串长//顺序串类型
//生成串
void StrAssign(SqString& s, char cstr[]) {
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i; //s为引用型参数//设置串s的长度
}
//销毁串
void DestroyStr(SqString& s)
{ }
//串的复制
void StrCopy(SqString& s, SqString t)
{//s为引用型参数
	int i;
	for (i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
	//复制t的所有字符//设置串s的长度
}
//判断串相等
bool StrEqual(SqString s, SqString t) {
	bool same = true;
	int i;
	if (s.length != t.length)
		same = false;
	else
		for (i = 0; i < s.length; i++)
			if (s.data[i] = t.data[i])
			{
				same = false;
				break;
			}
	return same;
}
int StrLength(SqString s)
{
	return s.length;
}
SqString Concat(SqString s, SqString t)
{
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++)
		str.data[i] = s.data[i];
	for (int i = 0; i < t.length; i++)
		str.data[s.length + i] = t.data[i];
	return str;
}
SqString SubStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || j<0 || i + j - 1>s.length)
		return str;
	for (k = i - 1; k < i + j - 1; k++)
		str.data[k - i + 1] = s.data[k];
	str.length = j;
	return str;
}
//字串插入
SqString InsStr(SqString s1, int i, SqString s2)
{
	int j;
	SqString str;	//定义结果串
	str.length = 0;
	if (i <= 0 || i > s1.length + 1)
		return str;
	for (j = 0; j < i - 1; j++)
		str.data[j] = s1.data[j];
	for (j = 0; j < s2.length; j++)
		str.data[i + j - 1] = s2.data[j];
	for (j = i - 1; j < s1.length; j++)
		str.data[s2.length + j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}
//字串的删除
SqString DelStr(SqString s, int i, int j)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}
//字串的替换
SqString RepStr(SqString s, int i, int j, SqString t)
{
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > s.length || i + j > s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++)
		str.data[i + k - 1] = t.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}
//输出串
void DispStr(SqString s)
{
	int i;
	if (s.length > 0)
	{
		for (i = 0; i < s.length; i++)
			printf("%c", s.data[i]);
		printf("\n");
	}
}
int Strcmp(SqString s, SqString t)
{
	int i, comlen;
	if (s.length < t.length)comlen = s.length;
	else comlen = t.length;
	for (i = 0; i < comlen; i++)
		if (s.data[i] > t.data[i])
			return 1;
		else if (s.data[i] < t.data[i])
			return -1;
	if (s.length == t.length)
		return 0;
	else
		return s.length > t.length ? 1 : -1;
}
int BF(SqString s, SqString t)
{
	int i = 0, j = 0;
	while (i < s.length && j < t.length)
	{
		if(s.data[i]==t.data[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1; j = 0;
		}
	}
	if (j >= t.length)
		return i - t.length;
	else
		return (-1);
}
void GetNext(SqString t, int next[])
{
	int j = 0, k = -1;
	next[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else k = next[k];
	}
}
int KMPIndex(SqString s, SqString t)
{
	int next[MaxSize], i = 0, j = 0;
	GetNext(t, next);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else j = next[j];

	}
	if (j >= t.length)
		return (i - t.length);//返回匹配模式串的首字符下标
	else
		return -1;
}
void GetNextal(SqString t, int nextval[])
{
	int j = 0, k = -1;
	nextval[0] = -1;
	while (j < t.length - 1)
	{
		if (k == -1 || t.data[j] == t.data[k])
		{
			j++;
			k++;
			if (t.data[j] != t.data[k])
				nextval[j] = k;
			else
				nextval[j] = nextval[k];
		}
		else k = nextval[k];
	}
}
int KMPIndex1(SqString s, SqString t)
{
	int nextval[MaxSize], i = 0, j = 0;
	GetNext(t, nextval);
	while (i < s.length && j < t.length)
	{
		if (j == -1 || s.data[i] == t.data[j])
		{
			i++;
			j++;
		}
		else j = nextval[j];

	}
	if (j >= t.length)
		return (i - t.length);//返回匹配模式串的首字符下标
	else
		return -1;
}
int main()
{
	SqString s, t;
	char a[] = "abcabcdabcdeabcdefabcdefg", b[] = "abcdeabcdefab";
	StrAssign(s, a);
	StrAssign(t, b);
	printf("BF:%d\n", BF(s, t));
	printf("KMP:%d\n", KMPIndex(s, t));
	printf("KMP1:%d\n", KMPIndex(s, t));
	
	return 0;
}