#include<iostream>
using namespace std;

const int MAXN = 250;

int f[MAXN][MAXN];
int n;

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> f[i][i];
    }

    for(int l = 2; l <= n; l++) {
        for(int i = 1; i + l - 1 <= n; i++) {
            int j = i + l - 1;

            for(int k = i; k <= j - 1; k++) {
                if(f[i][k] == f[k + 1][j]) {
                    f[i][j] = max(f[i][j], f[i][k] + 1);
                }
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