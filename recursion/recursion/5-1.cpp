#include<iostream>
using namespace std;
void move(char X, char Y)
{
	printf("%c-->%c\n", X, Y);
}
void Hanoil(int n, char A, char B, char C)
{
	if (n == 1)
		move(A, C);
	else
	{
		Hanoil(n - 1, A, C, B);
		move(A, C);
		Hanoil(n-1,B, A, C);
	}
}
int main()
{
	int n;
	cin >> n;
	Hanoil(n, 'A', 'B', 'C');

	return 0;
}