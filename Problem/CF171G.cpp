#include<iostream>
using namespace std;

int main() {
    int a[20], l;

    cin >> a[0] >> a[1] >> l;

    for(int i = 2; i <= l; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }

    cout << a[l] << endl;

    return 0;
}