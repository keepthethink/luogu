#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;

int f[MAXN], e[MAXN];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        f[i] = i;
        e[i] = i;
    }
}

int find(int k) {
    if(f[k] == k) {
        return k;
    }
    return f[k] = find(f[k]);
}

void connect(int a, int b) {
    f[find(a)] = find(b);
}

int count(int n) {
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        if(f[i] == i) {
            sum++;
        }
    }

    return sum;
}

int main() {
    int n, m;

    cin >> n >> m;

    init(n);
    for(int i = 1; i <= m; i++) {
        char c;
        int a, b;

        cin >> c >> a >> b;

        if(c == 'F') {
            connect(a, b);
        } else {
            if(e[a] == a) {
                e[a] = find(b);
            } else {
                connect(e[a], b);
            }

            if(e[b] == b) {
                e[b] = find(a);
            } else {
                connect(e[b], a);
            }
        }
    }

    cout << count(n) << endl;

    return 0;
}