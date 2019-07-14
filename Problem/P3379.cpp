#include<cstdio>
using namespace std;

const int MAXN = 500000 + 5;
const int MAXB = 21;

int head[MAXN], to[MAXN * 2], nxt[MAXN * 2];
int n, m, root;
int f[MAXN][MAXB];
int dep[MAXN];

void addEdge(int id, int x, int y) {
    to[id] = y;
    nxt[id] = head[x];
    head[x] = id;
}

void dfs(int u, int father) {
    dep[u] = dep[father] + 1;

    for(int i = 0; i <= 19; i++) {
        f[u][i + 1] = f[f[u][i]][i];
    }

    for(int i = head[u]; i != 0; i = nxt[i]) {
        int v = to[i];

        if(v == father) {
            continue; 
        }

        f[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if(dep[x] < dep[y]) {
        int t = x; x = y; y = t;
    }

    for(int i = 20; i >= 0; i--) {
        if(dep[f[x][i]] >= dep[y]) {
            x = f[x][i];
        }
    }

    if(x == y) {
        return x;
    }

    for(int i = 20; i >= 0; i--) {
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}

int main() {
    scanf("%d%d%d", &n, &m, &root);

    for(int i = 2; i <= n; i++) {
        int x, y;

        scanf("%d%d", &x, &y);
        addEdge(i * 2 - 1, x, y);
        addEdge(i * 2, y, x);
    }
    dfs(root, 0);

    for(int i = 1; i <= m; i++) {
        int x, y;

        scanf("%d%d", &x, &y);

        printf("%d\n", lca(x, y));
    }

    return 0;
}