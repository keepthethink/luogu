#include<iostream>
using namespace std;

int main() {
    int n, a = 1, b = 1;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int t = a;
        a = b;
        b = t + b;
    }

    cout << a << endl;

    return 0;
}