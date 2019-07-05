#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 50 + 5;

char s[MAXN];
int n, t;

int main() {
    cin >> n >> t;

    cin >> s;

    while(t--) {
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }

    cout << s << endl;

    return 0;
}