#include<iostream>
#include<map>
#include<string>
using namespace std;

const int MAXN = 20000 + 5;

map<string, int> num;
int f[MAXN];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        f[i] = i;
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

bool query(int a, int b) {
    return find(a) == find(b);
}

int main() {
    int n, m;

    cin >> n >> m;

    init(n);
    for(int i = 1; i <= n; i++) {
        string name;

        cin >> name;

        num[name] = i;
    }
    for(int i = 1; i <= m; i++) {
        string s1, s2;

        cin >> s1 >> s2;

        connect(num[s1], num[s2]);
    }

    int q;

    cin >> q;

    for(int i = 1; i <= q; i++) {
        string s1, s2;

        cin >> s1 >> s2;

        cout << (query(num[s1], num[s2]) ? "Yes." : "No.") << endl;
    }

    return 0;
}