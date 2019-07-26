#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;

int v[MAXN][MAXN], f[MAXN][MAXN];
int n, t;

int main() {
    cin >> n >> t;
    for(int i = 1; i <= t; i++) {
        int x, y;

        cin >> x >> y;
        v[x][y] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(v[i][j] == 0) {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans = max(ans, f[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}