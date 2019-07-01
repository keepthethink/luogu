#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

struct Line {
    int x, y1, y2, type;

    bool operator < (const Line& l) const {
        return x < l.x;
    }
};

struct TreeNode {
    int v; //被覆盖几次
    int length; //覆盖区间长度
    int sCount; //被几条不相交线段覆盖
    bool l, r; //左右节点是否被覆盖
};

const int MAXN = 5000 + 5;
const int MAXS = 10000;

TreeNode t[MAXN * 4 + 1];
Line line[MAXN * 2];
int n;
int lborder = INT_MAX, rborder = INT_MIN;

void input() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        line[i * 2 - 1].x = x1;
        line[i * 2 - 1].y1 = y1;
        line[i * 2 - 1].y2 = y2;
        line[i * 2 - 1].type = 1;

        line[i * 2].x = x2;
        line[i * 2].y1 = y1;
        line[i * 2].y2 = y2;
        line[i * 2].type = -1;

        lborder = min(lborder, min(y1, y2));
        rborder = max(rborder, max(y1, y2));
    }
}

void pushup(int now, int nowL, int nowR) {
    if(t[now].v != 0) {
        t[now].sCount = 1;
        t[now].length = nowR - nowL + 1;
        t[now].l = t[now].r = true;
    } else if(nowL == nowR) {
        t[now].sCount = 0;
        t[now].length = 0;
        t[now].l = t[now].r = false;
    } else {
        t[now].sCount = t[now >> 1].sCount + t[now >> 1 | 1].sCount;
        if(t[now >> 1].r == t[now >> 1 | 1].l) {
            t[now].sCount--;
        }
        t[now].length = t[now >> 1].length + t[now >> 1 | 1].length;
        t[now].l = t[now >> 1].l;
        t[now].r = t[now >> 1 | 1].r;
    }
}

void modify(int now, int maxL, int maxR, int nowL, int nowR, int v) {
    if ((maxL <= nowL) && (maxR >= nowR)) {
        t[now].v += v;
        pushup(now, nowL, nowR);
        return;
    }

    int mid = (nowL + nowR) / 2;

    if(maxL <= mid) {
        modify(now >> 1, maxL, maxR, nowL, mid, v);
    }
    if(mid < maxR) {
        modify(now >> 1 | 1, maxL, maxR, mid + 1, nowR, v);
    }
    pushup(now, nowL, nowR);
}

int getTotalLength() {
    return t[1].length;
}

int getSegmentCount() {
    return t[1].sCount;
}

int main() {
    input();

    if(lborder <= 0) {
        for(int i = 0; i < n * 2; i++) {
            line[i].y1 += -lborder + 1;
            line[i].y1 += -lborder + 1;
        }
        rborder -= lborder;
        lborder = 1;
    }

    sort(line, line + n * 2);

    int ans = 0, last = 0;
    for(int i = 0; i < n * 2; i++) {
        modify(1, line[i].y1, line[i].y2 - 1, 1, rborder, line[i].type);
        while(line[i].x == line[i + 1].x && line[i].type == line[i + 1].type) {
            i++;
            modify(1, line[i].y1, line[i].y2 - 1, 1, rborder, line[i].type);
        }
        ans += abs(t[1].length - last);
        last = t[1].length;
        ans += t[1].sCount * 2 * (line[i + 1].x - line[i].x);
    }

    cout << ans << endl;
}