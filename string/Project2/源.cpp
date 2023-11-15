
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 100005;

int cnt[N];


int hashFn(string s) {
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        res = res * 131 + s[i];
    }
    return res % N;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string name;
            cin >> name;
            int idx = hashFn(name);
            cnt[idx]++;
        }
    }

    int num = 0;
    string ans[100005];
    for (int i = 0; i < N; i++) {
        if (cnt[i] == n) {
            ans[num++] = to_string(i);
        }
    }

    sort(ans, ans + num);

    cout << num << endl;
    for (int i = 0; i < num; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
