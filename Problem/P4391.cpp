#include<cstdio>
using namespace std;

const int MAXN = 1000000 + 5;

char s[MAXN];
int next[MAXN];

int main() {
    int l;

    scanf("%d%s", &l, s + 1);

    int j = 0;
    for(int i = 2; i <= l; i++) {
        while(j != 0 && s[i] != s[j + 1]) {
            j = next[j];
        }

        if(s[i] == s[j + 1]) {
            j++;
        }

        next[i] = j;
    }

    printf("%d\n", l - next[l]);

    return 0;
}