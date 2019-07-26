#include<iostream>
#include<string>
#define OK 0
#define REPEAT 1
#define WRONG 2
using namespace std;

const int MAXN = 500000 + 5;

int c[MAXN][26], cnt = 0, val[MAXN];

void insert(string s) {
    int l = s.length(), now = 0;

    for(int i = 0; i < l; i++) {
        int v = s[i] - 'a';

        if(c[now][v] == 0) {
            c[now][v] = ++cnt;
        }

        now = c[now][v];
    }
}

int search(string s) {
    int l = s.length(), now = 0;

    for(int i = 0; i < l; i++) {
        int v = s[i] - 'a';

        if(c[now][v] == 0) {
            return WRONG;
        }

        now = c[now][v];
    }

    if(!val[now]) {
        val[now] = 1;
        return OK;
    }
    return REPEAT;
}

int main() {
    int n, m;

    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;

        cin >> s;

        insert(s);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        string s;

        cin >> s;

        int res = search(s);

        if(res == OK) {
            cout << "OK" << endl;
        } else if(res == REPEAT) {
            cout << "REPEAT" << endl;
        } else if(res == WRONG) {
            cout << "WRONG" << endl;
        }
    }

    return 0;
}