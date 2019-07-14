#include<iostream>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

const int MAXN = 100000 + 5;
const int MAXM = 200000 + 5;

int f[MAXN];
Edge edge[MAXM];
int n, m;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void input() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
}

int find(int k) {
    if(f[k] == k) {
        return k;
    }
    return f[k] = find(f[k]);
}

void connect(int x, int y) {
    f[find(x)] = find(y);
}

bool query(int x, int y) {
    return find(x) == find(y);
}

int main() {
    input();
    sort(edge + 1, edge + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }

    int ans = 0;
    for(int i = 1, cnt = 0; i <= m; i++) {
        if(query(edge[i].u, edge[i].v)) {
            //do nothing
        } else {
            connect(edge[i].u, edge[i].v);
            cnt++;
            ans = edge[i].w;
        }
        if(cnt == n - 1) {
            break;
        }
    }

    cout << n - 1 << " " << ans << endl;

    return 0;
}