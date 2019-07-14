#include<iostream>
#define int long long
using namespace std;

int exgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);

    int x1 = x, y1 = y;

    x = y1;
    y = x1 - (a / b) * y1;

    return r;
}

signed main() {
    int a, b, x, y;

    cin >> a >> b;
    exgcd(a, b, x, y);

    cout << (x % b + b) % b << endl;

    return 0;
}