#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 3000 + 5;

int s[MAXN], c[MAXN];
int n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    int ans = (1 << 30) - 1;
    for(int i = 2; i <= n - 1; i++) {
        int l = 0, r = 0;
        for(int p = 1; p <= i - 1; p++) {
            if(s[p] < s[i] && (l == 0 || c[p] < c[l])) {
                l = p;
            }
        }

        for(int q = i + 1; q <= n; q++) {
            if(s[q] > s[i] && (r == 0 || c[q] < c[r])) {
                r = q;
            }
        }

        if(l != 0 && r != 0) {
            ans = min(ans, c[l] + c[i] + c[r]);
        }
    }

    if(ans == (1 << 30) - 1) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}