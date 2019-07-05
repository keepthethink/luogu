#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<char> q;

    q.push('h');
    q.push('e');
    q.push('l');
    q.push('l');
    q.push('o');

    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == q.front()) {
            q.pop();
        }
    }

    if(q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}