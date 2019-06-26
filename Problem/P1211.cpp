#include<iostream>
using namespace std;

bool in[10];

bool check(int k) {
    while(k != 0) {
        if(!in[k % 10]) {
            return false;
        }
        k /= 10;
    }
    return true;
}

void input() {
    int n;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;

        cin >> k;
        in[k] = true;
    }
}

int main() {
    input();

    int ans = 0;
    for(int i = 100; i <= 999; i++) {
        for(int j = 10; j <= 99; j++) {
            int a = i * (j / 10), b = i * (j % 10), c = i * j;

            if(a > 999 || b > 999 || c > 9999) {
                continue;
            }

            if(check(i) && check(j) && check(a) && check(b) && check(c)) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}