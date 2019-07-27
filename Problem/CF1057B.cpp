#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 5000 + 5;

int a[MAXN], sum[MAXN];
int n;

int main() {
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(sum[j] - sum[i - 1] > 100 * (j - i + 1)) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}