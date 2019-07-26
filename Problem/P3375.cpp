#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 1000000 + 5;

char s1[MAXN], s2[MAXN];
int next[MAXN], l1, l2;

void calcNext() {
    int j = 0;

    next[1] = 0;
    for(int i = 2; i <= l2; i++) {
        while(j > 0 && s2[i] != s2[j + 1]) {
            j = next[j];
        }
        if(s2[i] == s2[j + 1]) { //找到匹配，后移一位
            j++;
        } //反之则为0

        next[i] = j;
    }
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    l1 = strlen(s1 + 1);
    l2 = strlen(s2 + 1);

    calcNext();

    int j = 0;

    for(int i = 1; i <= l1; i++) {
        while(j > 0 && s1[i] != s2[j + 1]) {
            j = next[j]; //无法往后匹配了，跳转
        }

        if(s1[i] == s2[j + 1]) {
            j++; //可以匹配，匹配位数加一
        }

        if(j == l2) {
            printf("%d\n", i - l2 + 1);
        }
    }

    for(int i = 1; i <= l2; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    return 0;
}