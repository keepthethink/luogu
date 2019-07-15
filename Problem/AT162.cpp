#include<iostream>
#include<string>
using namespace std;

int arr[256];

int main() {
    arr['A'] = 4;
    arr['B'] = 3;
    arr['C'] = 2;
    arr['D'] = 1;

    int n;
    string s;

    cin >> n >> s;

    int ans = 0;

    for(int i = 0; i < s.size(); i++) {
        ans += arr[(int)s[i]];
    }

    if(ans == 0) {
        cout << 0 << endl;
    } else {
        printf("%.14lf\n", (double)ans / (double)n);
    }

    return 0;
}