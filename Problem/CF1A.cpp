#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n, m;
    double a;

    cin >> n >> m >> a;

    cout << ((long long)(ceil(n / a))) * ((long long)(ceil(m / a))) << endl;

    return 0;
}