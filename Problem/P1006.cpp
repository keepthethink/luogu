#include<iostream>
using namespace std;

const int MAXN = 50 + 5;

int v[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];
int n, m;

void input() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
}

int main() {
    input();

    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= m; l++) {
                    f[i][j][k][l] = max(
                        max(f[i - 1][j][k - 1][l], f[i][j - 1][k - 1][l]),
                        max(f[i - 1][j][k][l - 1], f[i][j - 1][k][l - 1])
                    ) + v[i][j] + v[k][l];
                    if(i == k && j == l) {
                        f[i][j][k][l] -= v[i][j];
                    }
                }
            }
        }
    }

    cout << f[n][m][n][m] << endl;

    return 0;
}