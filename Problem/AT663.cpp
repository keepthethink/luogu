#include<iostream>
using namespace std;

int main() {
    int n;

    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int a, b, c, d, e;

        cin >> a >> b >> c >> d >> e;

        if(a + b + c + d + e < 20) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}