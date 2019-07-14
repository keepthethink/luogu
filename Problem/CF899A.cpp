#include<iostream>
using namespace std;

int main() {
    int n, cnt[3] = {0, 0, 0};

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;

        cin >> k;

        cnt[k]++;
    }

    int ans = min(cnt[1], cnt[2]);
    cnt[1] -= ans;
    cnt[2] -= ans;
    
    if(cnt[1] > 0) {
        ans += cnt[1] / 3;
    }

    cout << ans << endl;

    return 0;
}