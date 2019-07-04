#include<iostream>
using namespace std;

const int MAXN = 500000 + 5;

int tree[MAXN];
int n, m;

int lowbit(int k) {
    return k & (-k);
}

void add(int s, int v) {
    while(s <= n) {
        tree[s] += v;
        s += lowbit(s);
    }
}

int sum(int s) {
    int sum = 0;
    while(s > 0) {
        sum += tree[s];
        s -= lowbit(s);
    }
    return sum;
}

void input() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int k;

        cin >> k;

        tree[i] = k - tree[i - 1];
    }
}

int main() {
    input();

    for(int i = 1; i <= m; i++) {
        int c, x, y, k;

        cin >> c >> x;

        if(c == 1) {
            cin >> y >> k;

            add(x, k);
            add(y + 1, -k);
        } else {
            cout << sum(x) << endl;
        }
    }

    return 0;
}