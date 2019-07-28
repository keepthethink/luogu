#include<iostream>
using namespace std;

const int MAXN = 10 + 1;

int f[MAXN][MAXN];

int main() {
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 || j == 1) {
                f[i][j] = 1;
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }

    cout << f[n][n] << endl;

    return 0;
}