#include<iostream>
#include<algorithm>
using namespace std;

struct Data {
    int n, v;

    bool operator > (const Data& d) const {
        return v > d.v;
    }
};

const int MAXN = 1000 + 5;

Data data[MAXN];

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> data[i].v;
        data[i].n = i + 1;
    }

    sort(data, data + n, greater<Data>());

    cout << data[0].n << " " << data[1].v << endl;

    return 0;
}