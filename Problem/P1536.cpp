#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;

int father[MAXN];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int find(int k) {
    if(father[k] == k) {
        return k;
    }
    return father[k] = find(father[k]);
}

void connect(int a, int b) {
    father[find(a)] = find(b);
}

int main() {
    int n, m;

    cin >> n >> m;

    init(n);
    for(int i = 1; i <= m; i++) {
        int a, b;

        cin >> a >> b;

        connect(a, b);
    }

    int ans = -1;
    for(int i = 1; i <= n; i++) {
        if(father[i] == i) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}