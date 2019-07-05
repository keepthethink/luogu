#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100000 + 5;

long long sum[MAXN];

int main() {
    int n, k;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int v;

        cin >> v;

        sum[i] = v + sum[i - 1];
    }

    long long ans = (1 << 31);
    for(int i = 1; i + k - 1 <= n; i++) {
        ans = max(ans, sum[i + k - 1] - sum[i - 1]);
    }

    cout << ans << endl;

    return 0;
}