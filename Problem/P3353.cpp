#include<iostream>
using namespace std;

const int MAXN = 100000 + 5;

int tree[MAXN];
int n;

int lowbit(int k) {
    return k & (-k);
}

void update(int s, int v) {
    while(s <= n) {
        tree[s] += v;
        s += lowbit(s);
    }
}

int sum(int s) {
    int ans = 0;
    while(s > 0) {
        ans += tree[s];
        s -= lowbit(s);
    }
    return ans;
}

int main() {
    int w;

    cin >> n >> w;

    for(int i = 1; i <= n; i++) {
        int x, b;

        cin >> x >> b;
        update(x, b);
    }

    int ans = 0;
    for(int i = 1; i + w - 1 <= n; i++) {
        ans = max(ans, sum(i + w - 1) - sum(i - 1));
    }

    cout << ans << endl;

    return 0;
}