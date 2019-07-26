#include<iostream>
using namespace std;

string s;

bool lessThan(int p, int q) {
    int l = s.length();

    for(int i = 0; i < l; i++) {
        if(s[(p + i) % l] != s[(q + i) % l]) {
            return s[(p + i) % l] < s[(q + i) % l];
        }
    }

    return false;
}

int main() {
    int t;

    cin >> t;
    while(t--) {
        cin >> s;

        int ans = 0, l = s.length();

        for(int i = 1; i < l; i++) {
            if(lessThan(i, ans)) {
                ans = i;
            }
        }

        for(int i = 0; i < l; i++) {
            cout << s[(ans + i) % l];
        }
        cout << endl;
    }

    return 0;
}