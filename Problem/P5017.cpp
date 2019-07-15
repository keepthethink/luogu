#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 500 + 5;
const int MAXT = 4000000 + 5;

int t[MAXN], dp[MAXN][MAXN];
int n, m;

int dfs(int now, int s) {
    if(now == n + 1) {
        return 0;
    }

    if(s < t[now]) {
        return dfs(now, t[now]);
    }

    if(dp[now][s - t[now]] != 0) {
        return dp[now][s - t[now]];
    }

    int sum = 0, i = now;

    while(i <= n && t[i] <= s) { //车等人
        sum += t[i];
        i++;
    }

    int ans = s * (i - now) - sum + dfs(i, s + m);
    while(i <= n) { //人等车
        sum += t[i];
        ans = min(t[i] * (i - now + 1) - sum + dfs(i + 1, t[i] + m), ans);
        i++;
    }

    return dp[now][s - t[now]] = ans;
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    sort(t + 1, t + n + 1);

    cout << dfs(1, 0) << endl;

    return 0;
}