#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100000 + 5;
const int MAXB = 20;

int st[MAXN][MAXB], log2[MAXN];
int v[MAXN];
int n, m;

void input() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
}

void makeST() {
    log2[0] = -1;
    for(int i = 1; i <= n; i++) {
        st[i][0] = v[i];
        log2[i] = log2[i >> 1] + 1;
    }
    for(int j = 1; j <= log2[n]; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void query() {
    for(int i = 1; i <= m; i++) {
        int x, y;

        scanf("%d%d", &x, &y);
        int s = log2[y - x + 1];
        printf("%d\n", max(st[x][s], st[y - (1 << s) + 1][s]));
    }
}

int main() {
    input();
    makeST();
    query();

    return 0;
}