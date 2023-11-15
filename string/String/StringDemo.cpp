#include<iostream>
using namespace std;
const int MaxSize = 200;
typedef struct
{
	char data[MaxSize]; 
	int length;
}SqString; //��Ŵ��ַ�//��Ŵ���//˳������
//���ɴ�
void StrAssign(SqString& s, char cstr[]) {
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i; //sΪ�����Ͳ���//���ô�s�ĳ���
}
//���ٴ�
void DestroyStr(SqString&s)
{ }
//���ĸ���
void StrCopy(SqString& s, SqString t)
{//sΪ�����Ͳ���
	int i;
	for (i = 0; i < t.length; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
	//����t�������ַ�//���ô�s�ĳ���
}
//�жϴ����
bool StrEqual(SqString s,SqString t) {
	bool same=true; 
	int i; 
	if(s.length!=t.length)
		same=false; 
	else 
		for (i=0;i<s.length;i++) 
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
//�ִ�����
SqString InsStr(SqString s1, int i, SqString s2)
{
	int j;
	SqString str;	//��������
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
//�ִ���ɾ��
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
//�ִ����滻
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
//�����
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
int BF(SqString s,SqString t)
{
	int i = 0, j = 0;
	while(i<s.length&&j<t.length)//��������û��ɨ����ʱѭ��
	{
		if(s.data[i]==t.data[i])	//��ǰ�Ƚϵ������ַ���ͬ
		{
			i++;j++;
		}else
		{
			//��i���˵�i-j+1��λ�ã��Ա���һ�αȽϴ�s�ĵ�i-j+1���ַ���ʼ��
			//ͬʱ��j����Ϊ0���Ա��t�Ŀ�ͷ���¿�ʼ�Ƚϡ�
			i = i - j + 1; j = 0;
		}
	} 
	if(j >= t.length)	//j���磬��ʾt��s���Ӵ� 
		 return (i - t.length);
	else			//ģʽ��ƥ��ʧ�� 
		return (-1);
}
//next����Ļ�ȡ
void GetNext(SqString t,int next[])
{
	int j,k;
	j = 0;k = -1;//jɨ��t,k��¼t[j]֮ǰ��t��ͷ��ͬ���ַ����� 
	next[0] = -1;
	while(j<t.length-1)
	{
		if(k==-1||t.data[j] == t.data[k])
		{
			j++;k++;
			if(t.data[j]!=t.data[k]) 
				next[j] = k;
			else
			next[j] = next[k];
		}
		else k = next[k];	//k���� 
	}
}
//KMP�㷨
int KMPIndex(SqString s,SqString t)
{
	int next[MaxSize] ,i = 0,j = 0;
	GetNext(t,next);
	while(i<s.length&&j<t.length)
	{
		if(j==-1||s.data[i] == t.data[j])
		{
			i++;j++;
		}
		else j = next[j];
	}
	if(j>=t.length)
		return (i-t.length);//ƥ��ɹ��򷵻��Ӵ�λ�� 
	else
		return -1;
 } 
int main()
{
	
	return 0;
 } 
