#include<iostream>
#include<stack>
using namespace std;

const int MAXN = 200000 + 5;

int f[MAXN];
int n;

int main() {
    int n;

    cin >> n;
    for(int i = 2; i <= n; i++) {
        cin >> f[i];
    }

    int p = n;
    stack<int> s;

    while(p != 0) {
        s.push(p);
        p = f[p];
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}