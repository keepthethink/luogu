#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 100000 + 5;

int a[MAXN];
int n;
int d1[MAXN], d2[MAXN];

int main() {
    //freopen("input.txt", "r", stdin);

    int l1 = 1, l2 = 1;

    while (cin >> a[++n]); n--;

    d1[1] = a[1];
    d2[1] = a[1];

    for(int i = 2; i <= n; i++) {
        if(d1[l1] >= a[i]) {
            d1[++l1] = a[i];
        } else {
            int * p = upper_bound(d1 + 1, d1 + l1 + 1, a[i], greater<int>());
            *p = a[i];
        }
    }

    for(int i = 2; i <= n; i++) {
        if(d2[l2] < a[i]) {
            d2[++l2] = a[i];
        } else {
            int * p = lower_bound(d2 + 1, d2 + l2 + 1, a[i]);
            *p = a[i];
        }
    }

    cout << l1 << endl << l2 << endl;
}