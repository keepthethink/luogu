#include<iostream>
#include<algorithm>
using namespace std;

int cnt1[26], cnt2[26];

int main() {
    string s1, s2;

    while(cin >> s1 >> s2) {

    int l1 = s1.length(), l2 = s2.length();

    for(int i = 0; i < 26; i++) {
        cnt1[i] = 0;
        cnt2[i] = 0;
    }

    for(int i = 0; i < l1; i++) {
        cnt1[s1[i] - 'A']++;
    }

    for(int i = 0; i < l2; i++) {
        cnt2[s2[i] - 'A']++;
    }

    sort(cnt1, cnt1 + 26);
    sort(cnt2, cnt2 + 26);

    bool flag = true;
    for(int i = 0; i < 26; i++) {
        if(cnt1[i] != cnt2[i]) {
            cout << "NO" << endl;
            flag = false;
            break;
        }
    }

    if(!flag) {
        continue;
    }

    cout << "YES" << endl;
    }

    return 0;
}