#include<iostream>
using namespace std;

const int MAXN = 500000 + 5;

int tree[MAXN];
int n;

int lowbit(int k) {
    return k & (-k);
}

void add(int x, int v) {
    while(x <= n) {
        tree[x] += v;
        x += lowbit(x);
    }
}

int sum(int k) {
    int sum = 0;
    while(k > 0) {
        sum += tree[k];
        k -= lowbit(k);
    }
    return sum;
}

int main() {
    int w;

    cin >> n >> w;

    for(int i = 1; i <= w; i++) {
        int x, y;
        char c;

        cin >> c >> x >> y;

        if(c == 'x') {
            add(x, y);
        } else {
            cout << sum(y) - sum(x - 1) << endl;
        }
    }

    return 0;
}