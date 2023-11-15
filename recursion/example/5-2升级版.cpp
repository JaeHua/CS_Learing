#include<iostream>
using namespace std;
double a[1005];
double getMin(double a[], int start, int end) 
{
  if(start == end) 
    return a[start];

  int mid = start + (end - start) / 2;

  double minLeft = getMin(a, start, mid);
  double minRight = getMin(a, mid+1, end);

  return min(minLeft, minRight);
}

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
    
  double minn = getMin(a, 0, n-1);
  cout << minn << endl;
}

