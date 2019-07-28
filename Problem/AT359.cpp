#include<iostream>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    cout << (n * (n + 1) * (n * 2 + 1) / 6) % m << endl;

    return 0;
}