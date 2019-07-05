#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;

    cin >> s;

    int top = 0, l = s.length(), ans = 0;

    for(int i = 0; i < l; i++) {
        if(s[i] == '(') {
            top++;
        } else if(top > 0) {
            ans += 2;
            top--;
        }
    }

    cout << ans << endl;

    return 0;
}