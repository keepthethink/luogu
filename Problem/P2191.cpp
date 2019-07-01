#include<stdio.h>

const int MAXN = 1000 + 5;

char way[MAXN][MAXN], text[MAXN][MAXN], ans[MAXN * MAXN];
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
                ans[cur++] = text[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= 0; j--) {
            if(way[j][i] == 'O') {
                ans[cur++] = text[i][n - j - 1];
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(way[i][j] == 'O') {
                ans[cur++] = text[n - i - 1][n - j - 1];
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(way[j][i] == 'O') {
                ans[cur++] = text[n - i - 1][j];
            }
        }
    }

    ans[cur] = '\0';

    printf("%s\n", ans);

    return 0;
}