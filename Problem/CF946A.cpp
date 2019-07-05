#include<iostream>
using namespace std;

int main() {
    int n, sum = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int v;

        cin >> v;

        sum += (v > 0 ? v : -v);
    }

    cout << sum << endl;

    return 0;
}