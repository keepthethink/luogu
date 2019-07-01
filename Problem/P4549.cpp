#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, ans;

    cin >> n >> ans;

    for(int i = 1; i <= n - 1; i++) {
        int k;

        cin >> k;

        ans = gcd(ans, k);
    }

    cout << abs(ans) << endl;

    return 0;
}