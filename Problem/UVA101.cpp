#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 30;

vector<int> b[MAXN];
int n;

void find(int a, int& p, int& h) {
    for(p = 0; p < n; p++) {
        for(h = 0; h < b[p].size(); h++) {
            if(b[p][h] == a) {
                return;
            }
        }
    }
}

void reset(int p, int h) {
    for(int i = h + 1; i < b[p].size(); i++) {
        b[b[p][i]].push_back(b[p][i]);
    }
    b[p].resize(h + 1);
}

void move(int p, int h, int p2) {
    for(int i = h; i < b[p].size(); i++) {
        b[p2].push_back(b[p][i]);
    }
    b[p].resize(h);
}

int main() {
    cin  >> n;

    for(int i = 0; i < n; i++) {
        b[i].push_back(i);
    }

    string s1, s2;
    int b1, b2;

    while(cin >> s1 >> b1 >> s2 >> b2) {
        int p1, h1, p2, h2;

        find(b1, p1, h1);
        find(b2, p2, h2);

        if(p1 == p2) {
            continue;
        }

        if(s1 == "move") {
            reset(p1, h1);
        }
        if(s2 == "onto") {
            reset(p2, h2);
        }

        move(p1, h1, p2);
    }

    for(int i = 0; i < n; i++) {
        cout << i << ":";

        for(int j = 0; j < b[i].size(); j++) {
            cout << " " << b[i][j];
        }
        cout << endl;
    }

    return 0;
}