#include<iostream>
using namespace std;

int main() {
    int a[105];

    cin >> a[0];
    for(int i = 1; i <= a[0]; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 1; i <= a[0]; i++) {
        ans += i * a[i];
    }

    cout << ans << endl;

    return 0;
}