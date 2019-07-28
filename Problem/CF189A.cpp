#include<iostream>
using namespace std;

const int MAXN = 4000 + 5;

int f[MAXN];

int main() {
    int n, a, b, c;

    cin >> n >> a >> b >> c;

    f[a] = 1;
    f[b] = 1;
    f[c] = 1;
    for(int i = 1; i <= n; i++) {
        if(i >= a && f[i - a] != 0) {
            f[i] = max(f[i], f[i - a] + 1);
        }
        if(i >= b && f[i - b] != 0) {
            f[i] = max(f[i], f[i - b] + 1);
        }
        if(i >= c && f[i - c] != 0) {
            f[i] = max(f[i], f[i - c] + 1);
        }
    }

    cout << f[n] << endl;

    return 0;
}