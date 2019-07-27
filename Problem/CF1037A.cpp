#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;

    cin >> n;

    cout << floor(log2(n)) + 1 << endl;

    return 0;
}