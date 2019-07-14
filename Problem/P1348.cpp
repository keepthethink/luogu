#include<iostream>
using namespace std;

int main() {
    long long a, b;

    cin >> a >> b;

    int ans = 0;
    for(long long i = a; i <= b; i++) {
        if(i % 2 != 0 || i % 4 == 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}