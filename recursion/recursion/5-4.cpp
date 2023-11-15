#include<iostream>
using namespace std;
int quickpow(int a, int n)
{
	int ans = 1;
	while (n > 0)
	{
		if (n & 1 > 0)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}
int main() {
	int x, n;
	cin >> x >> n;
	printf("%d", quickpow(x, n));
	return 0;
}