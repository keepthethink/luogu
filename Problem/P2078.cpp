#include<iostream>
#include<map>
using namespace std;

map<int, int> f;
int n, m, p, q;

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
    cin >> n >> m >> p >> q;

    for(int i = 1; i <= n; i++) {
        f[i] = i; 
    }

    for(int i = 1; i <= m; i++) {
        f[-i] = -i;
    }

    for(int i = 1; i <= p + q; i++) {
        int x, y;

        cin >> x >> y;

        connect(x, y);
    }

    int ans1 = 0, ans2 = 0;

    for(int i = 1; i <= n; i++) {
        if(query(1, i)) {
            ans1++;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(query(-1, -i)) {
            ans2++;
        }
    }

    cout << min(ans1, ans2) << endl;

    return 0;
}