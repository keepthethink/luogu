#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 100000 + 5;

char s1[MAXN], s2[MAXN];
int next[MAXN], l1, l2;

void calcNext() {
    int j = 0;

    next[1] = l2;

    for(int i = 2; i <= l2; i++) {
        while(j > 0) {
            j = next[j];
        }
    }
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    l1 = strlen(s1 + 1);
    l2 = strlen(s2 + 1);


}