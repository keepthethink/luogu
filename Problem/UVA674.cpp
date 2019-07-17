#include<iostream>
using namespace std;

const int MAXN = 8000;
const int w[6] = {0, 1, 5, 10, 25, 50};

int f[8000];

int main() {
    f[0] = 1;
    for(int i = 1; i <= 5; i++) {
        for(int j = w[i]; j < MAXN; j++) {
            f[j] += f[j - w[i]];
        }
    }

    int n;

    while(cin >> n) {
        cout << f[n] << endl;
    }

    return 0;
}