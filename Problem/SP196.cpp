#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 100 * 2 + 5;

int w[MAXN][MAXN], f[MAXN][MAXN];
int n;

int main() {
    int t;

    cin >> t;
    while(t--) {
        memset(f, 0, sizeof(f));
        memset(w, 0, sizeof(w));

        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                w[i][j] = c - '0';
                w[i + n][j + n] = w[i + n][j] = w[i][j + n] = w[i][j];
            }
        }

        for(int l = 1; l <= n + 1; l++) {
            for(int i = 1; i + l - 1 <= n * 2; i++) {
                int j = i + l - 1;

                if(l <= 2) {
                    f[i][j] = 1;
                    continue;
                }

                for(int k = i; k <= j; k++) {
                    if(f[i][k] && f[k][j] && (w[i][k] || w[j][k])) {
                        f[i][j] = 1;
                        break;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(f[i][i + n]) {
                ans++;
            }
        }
        cout << ans << endl;
        for(int i = 1; i <= n; i++) {
            if(f[i][i + n]) {
                cout << i << endl;
            }
        }
    }

    return 0;
}