#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 1000 + 5;

int v[MAXN];
int n;

void input() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

int main() {
    input();
    sort(v, v + n);
    int i = n - 1, j = 0;
    while(i > j) {
        cout << v[i] << endl;
        cout << v[j] << endl;
        i--; j++;
    }
    if(n % 2 == 1) {
        cout << v[n / 2] << endl;
    }

    return 0;
}