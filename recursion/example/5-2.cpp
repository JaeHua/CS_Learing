#include<iostream>
using namespace std;
double a[1005];
double getMin(double a[], int i)
{
	double minn;
	if(i == 0)
		return a[0];
	else
	{
		minn = getMin(a,i-1);
		if(minn>a[i])return a[i];
		else return minn;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n;i++)
		cin>>a[i];
	double minn = getMin(a,n-1);
	cout<<minn<<endl;
	return 0;
} 
