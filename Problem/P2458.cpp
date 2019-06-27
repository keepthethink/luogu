#include<iostream>
using namespace std;

const int MAXN = 1500 + 5;
const int INF = (1 << 30) - 1;

int head[MAXN * 2], to[MAXN * 2], nxt[MAXN * 2];
int n, cnt = 0;
int cost[MAXN], f[MAXN][3];
bool son[MAXN];

void addEdge(int id, int u, int v) {
    to[id] = v;
    nxt[id] = head[u];
    head[u] = id;
}

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int id;

        cin >> id;
        cin >> cost[id];
        int m;

        cin >> m;
        for(int i = 1; i <= m; i++) {
            int u;

            cin >> u;

            addEdge(++cnt, id, u);
            addEdge(++cnt, u, id);
        }
    }
}

void dp(int u, int father) {
    /*
    f[u][0]:被父节点看守
    f[u][1]:被子节点看守
    f[u][2]:被自身看守
    */
    f[u][2] = cost[u];
    for(int i = head[u]; i != 0; i = nxt[i]) {
        int v = to[i];

        if(v == father) {
            continue;
        }
        dp(v, u);
        f[u][0] += min(f[v][1], f[v][2]);
        f[u][2] += min(f[v][0], min(f[v][1], f[v][2]));
    }
    f[u][1] = INF;
    for(int i = head[u]; i != 0; i = nxt[i]) {
        int v = to[i];

        if(v == father) {
            continue;
        }
        f[u][1] = min(f[u][1], f[u][0] - min(f[v][1], f[v][2]) + f[v][2]);
    }
}

int main() {
    input();
    dp(1, 0);
    cout << min(f[1][1], f[1][2]) << endl;

    return 0;
}