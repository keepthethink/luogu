#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN], f[MAXN];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = (a[i - 1] <= a[i] ? f[i - 1] + 1 : 1);
        ans = max(ans, f[i]);
    }

    cout << ans << endl;

    return 0;
}