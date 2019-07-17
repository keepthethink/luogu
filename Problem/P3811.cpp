#include<cstdio>
#define int long long
using namespace std;

const int MAXN = 3000000 + 5;

int inv[MAXN];

signed main() {
    int n, p;

    scanf("%lld%lld", &n, &p);

    inv[1] = 1;
    for(int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld\n", inv[i]);
    }

    return 0;
}