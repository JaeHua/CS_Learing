#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;
const int MOD = 998244353;
int mu[MAXN + 1];
typedef long long ll;
const double M_E = 2.71828;
// Ԥ���������(����ƽ������)

bool hasSquareFactor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % (i * i) == 0) return true;
    }
    return false;
}
int getMu(int n) {
    if (n == 1) return 1;
    if (hasSquareFactor(n)) return 0;

    int result = 1;
    for (int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count > 0) {
            result *= pow(-1, count);
        }
    }
    if (n > 1) result *= -1;
    return result;
}

double logg(long long n) {
    return log2(n) / log2(exp(1)); //ת��Ϊ��eΪ�׵Ķ���
}

// ����S(n)  

long long S(long long n) {
    long long result = 0;
    for (long long d = 1; d <= n; d++) {
        if (n % d == 0) {
            result += mu[d] * logg(d);
            result %= MOD; //ȡģ
        }
    }
    return result;
}

// �̺�������ͬǰ


// ������(�����)
long long quickPow(long long a, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}


int main() {
    for (int i = 1; i <= 2000; i++)
    {
        mu[i] = getMu(i);
  
    }

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        ll n;

        cin >> n;

        ll sn = S(n);
        ll ans = quickPow(M_E, sn);

        cout << ans << " ";
    }
}
