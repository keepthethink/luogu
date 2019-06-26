#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;

int a[MAXN][MAXN];
int n, m;

int num, pos[MAXN][2], ans[MAXN][MAXN], f[MAXN][MAXN];
bool v[MAXN][MAXN];

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;

            cin >> c;
            a[i][j] = c - '0';
        }
    }
}

void dfs(int x, int y) {
    num++;
    ans[num][0] = x;
    ans[num][1] = y;
}



int main() {
    input();
}
