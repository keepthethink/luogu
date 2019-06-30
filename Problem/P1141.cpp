#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;
const int dx[] = {1, 1, 0, 0};
const int dy[] = {1, 0, 1, 0};

int a[MAXN][MAXN];
int n, m;

int num, pos[MAXN][2], f[MAXN][MAXN];
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

bool check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void dfs(int x, int y) {
    num++;
    pos[num][0] = x;
    pos[num][1] = y;
    for(int i = 0; i < 4; i++) {
        if(check(x + dx[i], y + dy[i])) {
            if(!v[x + dx[i]][y + dy[i]] && a[x][y] != a[x + dx[i]][y + dy[i]]) {
                v[x][y] = true;
                dfs(x + dx[i], y + dy[i]);
            }
        }
    }
}

int main() {
    input();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!v[i][j]) {
                num = 0;
                v[i][j] = true;
                dfs(i, j);

                for(int i = 1; i <= num; i++) {
                    f[pos[i][0]][pos[i][2]] = num;
                }
            }
        }
    }

    for(int i = 1; i <= m; i++) {
        int x, y;

        cin >> x >> y;
        cout << f[x][y] << endl;
    }

    return 0;
}
