#include<iostream>
#include<cmath>
using namespace std;

struct Node {
    double x, y;
};

struct Line {
    double u, v, w;
};

const int MAXN = 1000 + 5;
const int MAXM = 500 + 5;

Node node[MAXN], Line[MAXN * MAXN / 2];
int mon[MAXM], f[MAXN];
int m, n, l = 0;

double dist(Node a, Node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    cin >> m >> n;

    for(int i = 1; i <= m; i++) {
        cin >> mon[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> node[i].x >> node[i].y;
    }

    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            
        }
    }
}