#include<iostream>
using namespace std;

const int MAXN = 1000 + 5;

int sub[MAXN][MAXN];

int main() {
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for(int j = x1; j <= x2; j++) {
            sub[j][y1] += 1;
            sub[j][y2 + 1] += -1;
        }
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += sub[i][j];
            cout << sum << " ";
        }
        cout << endl;
    }

    return 0;
}