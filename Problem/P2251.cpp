#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000000 + 5;
const int MAXB = 20;

int st[MAXN][MAXB], log2[MAXN];
int n, m;

int query(int x, int y) {
    return min(st[x][log2[y - x + 1]], st[y - (1 << log2[y - x + 1]) + 1][log2[y - x + 1]]);
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> st[i][0];
    }

    log2[1] = 0;
    for(int i = 2; i <= n; i++) {
        log2[i] = log2[i / 2] + 1;
    }

    for(int j = 1; j <= log2[n]; j++) {
        for(int i = 1; i <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1; i <= n - m + 1; i++) {
        cout << query(i, i + m - 1) << endl;
    }

    return 0;
}