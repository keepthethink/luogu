#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;

    getline(cin, s);

    bool flag = false;
    for(int i = 0; i < s.length(); i++) {
        if(!(s[i] == '/' && (i == s.length() - 1 || s[i + 1] == '/'))) {
            cout << s[i];
            flag = true;
        }
    }

    if(!flag) {
        cout << "/";
    }

    cout << endl;

    return 0;
}