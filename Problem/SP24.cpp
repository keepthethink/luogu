#include<iostream>
using namespace std;

const int MAXN = 100 + 5;

int ans[MAXN * MAXN];

void fact(int n) {
    int bit = 1;

    ans[1] = 1;
    for(int i = 1; i <= n; i++) {
        int v = 0;

        for(int j = 1; j <= bit; j++) {
            ans[j] = ans[j] * i + v;
            v = ans[j] / 10;
            ans[j] %= 10;
        }

        while(v != 0) {
            bit++;
            ans[bit] = v % 10;
            v /= 10;
        }
    }

    for(int i = bit; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    int t;

    cin >> t;

    while(t--) {
        int n;

        cin >> n;

        fact(n);
    }

    return 0;
}