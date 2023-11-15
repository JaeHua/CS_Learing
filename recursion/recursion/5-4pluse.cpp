#include<iostream>
using namespace std;
int  n;
double x;
double expx(double x, int n)
{
	if (n == 1)
		return x;
	else if (!(n & 1))
	{
		return expx(x, n / 2) * expx(x, n / 2);
	}
	else
		return expx(x, (n - 1) / 2) * expx(x, (n - 1) / 2) * x;
}
int main() {
	cin >> x >> n;
	printf("%f", expx(x, n));
	return 0;
}