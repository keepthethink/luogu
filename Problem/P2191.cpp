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
                ans[cur++] = text[i][j];
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(way[i][j] == 'O') {
                ans[cur++] = text[j][i];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(way[i][j] == 'O') {
                ans[cur++] =text[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(way[i][j] == 'O') {
                ans[cur++] =text[i][j];
            }
        }
    }

    ans[cur++] = '\0';

    printf("%s\n", ans);

    return 0;
}