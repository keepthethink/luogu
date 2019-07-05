#include<iostream>
#include<set>
#include<string>
using namespace std;

const int MAXN = 200000 + 5;

string s[MAXN];

int main() {
    set<string> record;
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = n; i >= 1; i--) {
        if(record.find(s[i]) != record.end()) {
            continue;
        }
        cout << s[i] << endl;
        record.insert(s[i]);
    }

    return 0;
}