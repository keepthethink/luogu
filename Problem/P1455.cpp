#include<iostream>
using namespace std;

const int MAXN = 10000 + 5;

int father[MAXN];
int w[MAXN], v[MAXN];
int f[MAXN];
int n, e, m;

int find(int k) {
    if(k == father[k]) {
        return k;
    }
    return father[k] = find(father[k]);
}

int main() {
    cin >> n >> e >> m;

    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        father[i] = i;
    }

    for(int i = 1; i <= e; i++) {
        int x, y;

        cin >> x >> y;

        father[find(x)] = find(y);
    }

    for(int i = 1; i <= n; i++) {
        if(i != father[i]) {
            w[find(i)] += w[i];
            v[find(i)] += v[i];
            w[i] = v[i] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }

    cout << f[m] << endl;

    return 0;
}