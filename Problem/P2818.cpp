#include<cstdio>
#include<cctype>
using namespace std;

char s[1000 + 5];

int main() {
    int n;

    scanf("%d%s", &n, s);

    int res = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        res = (res * 10 + s[i] - '0') % n;
    }

    if(res == 0) {
        res = n;
    }

    printf("%d\n", res);

    return 0;
}