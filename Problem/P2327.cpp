#include<iostream>
using namespace std;

const int MAXN = 10000 + 5;

int a[MAXN], f[MAXN];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 2;

    f[1] = 0;
    for(int i = 2; i <= n + 1; i++) {
        f[i] = a[i - 1] - f[i - 1] - f[i - 2];
        if(f[i] < 0 || 1 < f[i]) {
            ans--;
            break;
        }

        if(i == n + 1 && f[i] != 0) {
            ans--;
            break;
        }
    }

    f[1] = 1;
    for(int i = 2; i <= n + 1; i++) {
        f[i] = a[i - 1] - f[i - 1] - f[i - 2];
        if(f[i] < 0 || 1 < f[i]) {
            ans--;
            break;
        }

        if(i == n + 1 && f[i] != 0) {
            ans--;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}