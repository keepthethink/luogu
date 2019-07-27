#include<cstdio>
#include<algorithm>
using namespace std;

int a[31];

int lg(int n) {
    if(n == 1) {
        return 0;
    }

    int res = 0;

    while(n) {
        n = n >> 1;
        res++;
    }

    return res == 0 ? 0 : res - 1;
}

int sum(int n) {
    int res = 0;

    while(n) {
        res += ((n & 1) != 0 ? 1 : 0);
        n = n >> 1;
    }

    return res;
}

signed main() {
    int n, q;

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        int k;

        scanf("%d", &k);
        a[lg(k)]++;
    }

    for(int i = 1; i <= q; i++) {
        int k;

        scanf("%d", &k);

        int ans = 0;
        for(int j = 30; j >= 0; j--) {
            int s = min(a[j], k / (1 << j));
            ans += s;
            k -= s * (1 << j);
        }

        if(k == 0) {
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}