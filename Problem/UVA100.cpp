#include<iostream>
#include<algorithm>
using namespace std;

int solve(int n) {
    int res = 1;
    while(n != 1) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        res++;
    }
    return res;
}

int main() {
    int a, b;

    while(cin >> a >> b) {
        int ans = 0;

        for(int i = min(a, b); i <= max(a, b); i++) {
            ans = max(ans, solve(i));
        }

        cout << a << " " << b << " " << ans << endl;
    }

    return 0;
}