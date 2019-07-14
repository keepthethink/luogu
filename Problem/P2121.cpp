#include<iostream>
#include<algorithm>
using namespace std;

struct Edge {
    int u, v, w;

    bool operator < (const Edge& e) const {
        return w > e.w;
    }
};

const int MAXN = 10000000 + 5;
const int MAXM = 10000000 + 5;

Edge edge[MAXM];
int f[MAXN];
int n, m, k;

int find(int k) {
    if(k == f[k]) {
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
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }

    sort(edge + 1, edge + n + 1);

    long long ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!query(edge[i].u, edge[i].v)) {
            connect(edge[i].u, edge[i].v);
            cnt++;
            ans += edge[i].w;

            if(cnt >= k) {
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}