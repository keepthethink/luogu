#include<iostream>
using namespace std;

const int MAXN = 100 + 5;

int v[MAXN];
int n;

int main() {
    cin >> n;

    for(int i = 1; i < MAXN; i++) {
        v[i] = n;
    }

    for(int i = 1; i <= n; i++) {
        int r;

        cin >> r;

        for(int j = 1; j <= r; j++) {
            int k;

            cin >> k;

            v[k]--;
        }
    }

    for(int i = 1; i < MAXN; i++) {
        if(v[i] == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}