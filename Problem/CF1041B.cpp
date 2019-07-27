#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int t = gcd(c, d);
    c /= t; d /= t;

    cout << min(a / c, b / d) << endl;

    return 0;
}