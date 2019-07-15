#include<iostream>
using namespace std;

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

int main() {
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b;

        cin >> a >> b;

        for(int i = a; i <= b; i++) {
            if(isPrime(i)) {
                cout << i << endl;
            }
        }
        cout << endl;
    }

    return 0;
}