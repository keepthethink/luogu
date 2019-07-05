#include<iostream>
using namespace std;

int main() {
    int n, ans = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        char c;

        cin >> c;

        if(c == '+') {
            ans++;
        }
        if(c == '-') {
            ans--;
        }
        if(ans < 0) {
            ans = 0;
        }
    }

    cout << ans << endl;

    return 0;
}