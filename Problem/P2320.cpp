#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    stack<int> ans;

    cin >> n;
    while(n != 0) {
        ans.push((n + 1) / 2);
        n = n / 2;
    }

    cout << ans.size() << endl;
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}