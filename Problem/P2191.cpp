#include<stdio.h>

const int MAXN = 1000 + 5;

char way[MAXN][MAXN], text[MAXN][MAXN], ans[MAXN];
int n;

void input() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", way[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%s",text[i]);
    }
}

int main() {
    input();

    int cur = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(way[i][j] == 'O') {
                ans[cur++] = way[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            ans[cur++] = way[j][i];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[cur++] = way[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[cur++] = way[i][j];
        }
    }

    return 0;
}