#include<iostream>
using namespace std;

const int MAXN = 10;

int v[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];
int n;

void input() {
    int x, y, k;

    cin >> n;

    while(1) {
        cin >> x >> y >> k;
        if(x == 0 && y == 0 && k == 0) {
            break;
        }
        v[x][y] = k;
    }
}

int main() {
    input();

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    f[i][j][k][l] = max(
                        max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]),
                        max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1])
                    ) + v[i][j] + v[k][l];

                    if(i == k && j == l) {
                        f[i][j][k][l] -= v[i][j];
                    }
                }
            }
        }
    }

    cout << f[n][n][n][n] << endl;

    return 0;
}