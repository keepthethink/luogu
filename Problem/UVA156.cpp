#include<iostream>
#include<vector>
#include<map>
#include<cctype>
#include<algorithm>
using namespace std;

string repr(string s) {
    for(int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    map<string, int> cnt;
    vector<string> words, ans;
    string s;

    while(cin >> s) {
        if(s[0] == '#') {
            break;
        }

        words.push_back(s);
        string r = repr(s);

        if(cnt.count(r) == 0) {
            cnt[r] = 0;
        }
        cnt[r]++;
    }

    for(int i = 0; i < words.size(); i++) {
        if(cnt[repr(words[i])] == 1) {
            ans.push_back(words[i]);
        }
    }

    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}