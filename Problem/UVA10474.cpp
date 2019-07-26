#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 10000;

int a[MAXN];

int main() {
    int n, q, x, t = 0;

    while(1) {
        scanf("%d%d", &n, &q);

        if(n == 0 && q == 0) {
            break;
        }

        printf("CASE# %d:\n", ++t);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a + n);

        while(q--) {
            scanf("%d", &x);

            int p = lower_bound(a, a + n, x) - a;
            
            if(p < n && a[p] == x) {
                printf("%d found at %d\n", x, p + 1);
            } else {
                printf("%d not found\n", x);
            }
        }
    }

    return 0;
}