#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

struct Line {
    int x1, x2, y;
    int type;

    bool operator < (const Line& l) const {
        if(y == l.y) {
            return type > l.type;
        }
        return y < l.y;
    }
};

struct Tree {
    int v, sCount, length, l, r;
};

const int MAXN = 5000 + 5;
const int MAXM = 10000 * 2 + 5;

Line line[MAXN * 2];
Tree t[MAXM * 4 + 2];

int n, m;
int lborder = INT_MAX, rborder = INT_MIN;

void pushup(int now, int nowL, int nowR) {
    if(t[now].v) {
        t[now].sCount = 1;
        t[now].length = nowR - nowL + 1;
        t[now].l = t[now].r = 1;
    } else {
        if(nowL == nowR) {
            t[now].sCount = 0;
            t[now].length = 0;
            t[now].l = t[now].r = 0;
        } else {
            t[now].sCount = t[now << 1].sCount + t[now << 1 | 1].sCount;
            t[now].length = t[now << 1].length + t[now << 1 | 1].length;

            if(t[now << 1].r && t[now << 1 | 1].l) {
                t[now].sCount--;
            }

            t[now].l = t[now << 1].l;
            t[now].r = t[now << 1 | 1].r;
        }
    }
}

void modify(int now, int nowL, int nowR, int maxL, int maxR, int v) {
    if(maxL <= nowL && nowR <= maxR) {
        t[now].v += v;
        pushup(now, nowL, nowR);
        return;
    }

    int mid = (nowL + nowR) / 2;

    if(maxL <= mid) {
        modify(now << 1, nowL, mid, maxL, maxR, v);
    }
    if(mid < maxR) {
        modify(now << 1 | 1, mid + 1, nowR, maxL, maxR, v);
    }
    pushup(now, nowL, nowR);
    return;
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        line[i * 2 - 1].x1 = x1;
        line[i * 2 - 1].x2 = x2;
        line[i * 2 - 1].y = y1;
        line[i * 2 - 1].type = 1;

        line[i * 2].x1 = x1;
        line[i * 2].x2 = x2;
        line[i * 2].y = y2;
        line[i * 2].type = -1;

        lborder = min(lborder, min(x1, x2));
        rborder = max(rborder, max(x1, x2));
    }

    if(lborder <= 0) {
        for(int i = 1; i <= n * 2; i++) {
            line[i].x1 += -lborder + 1;
            line[i].x2 += -lborder + 1;
        }
        rborder -= lborder;
    }

    sort(line + 1, line + n * 2 + 1);

    int ans = 0, last = 0;
    for(int i = 1; i <= n * 2; i++) {
        modify(1, 1, rborder, line[i].x1, line[i].x2 - 1, line[i].type);

        while(line[i].y == line[i + 1].y && line[i].type == line[i + 1].type) {
            i++;
            modify(1, 1, rborder, line[i].x2, line[i].x2 - 1, line[i].type);
        }

        ans += abs(t[1].length - last);
        last = t[1].length;
        ans += t[1].sCount * 2 * (line[i + 1].y - line[i].y);
    }

    cout << ans << endl;

    return 0;
}