//P1001 A + B Problem
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<stdio.h>

const int MAXN = 100001;
const int MAXM = 500001;

struct Line {
    int v;
    int p;
    int next;
};

struct Node {
    int dist;
    int heapLink;
};

int headLine[MAXN];
Line line[MAXM];
Node node[MAXN];
int h[MAXN];
int n, m, s, a, b;

//debug
void print() {
    for(int i = 1; i <= n; i++) {
        printf("%d ", node[i].dist);
    }
    printf("\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n\n");
}

int read() {
    bool flag = false;
    char c = ' ';
    int res = 0;
    
    while(c != '-' && (c < '0' || c > '9')){
        c = getchar();
    }
    
    if(c == '-') {
        flag = true;
    } else {
        res = c - '0';
    }
    
    c = getchar();
    while(c >= '0' && c <= '9') {
        res = res * 10 + c - '0';
        c = getchar();
    }
    
    if(flag) {
        return -res;
    }
    
    return res;
}

inline void write(int n) {
    if(n == 0) {
        putchar('0');
    }
    int d[15], num = 0;
    while(n != 0) {
        d[num++] = n % 10;
        n /= 10;
    }
    num--;
    while(num >= 0) {
        putchar(d[num--] + '0');
    }
    putchar('\n');
}

void addLine(int lId, int x, int y, int z) {
    line[lId].p = y;
    line[lId].v = z;
    line[lId].next = headLine[x];
    headLine[x] = lId;
}

void swap(int i, int j) {
    int x = h[i];
    h[i] = h[j];
    h[j] = x;
    node[h[i]].heapLink = i;
    node[h[j]].heapLink = j;
}

void up(int i) {
    while ((i != 1) && (node[h[i / 2]].dist > node[h[i]].dist)) {
        swap(i, i / 2);
        i /= 2;
    }
}

void down(int i, int hn) {
    int j = i * 2;
    while (j <= hn) {
        if ((j < hn) && (node[h[j]].dist > node[h[j + 1]].dist)) {
            j++;
        }
        if (node[h[i]].dist > node[h[j]].dist) {
            swap(i, j);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

void update(int now) {
    node[now].heapLink = 0;
    int i = headLine[now];
    while (i != 0) {
        int p = line[i].p;
        if (node[p].heapLink != 0) {
            if (node[now].dist + line[i].v < node[p].dist) {
                node[p].dist = node[now].dist + line[i].v;
                up(node[p].heapLink);
            }
        }
        i = line[i].next;
    }
}

int main() {
    a = read();
    b = read();
    
    n = 3;
    m = 2;
    s = 1;
    
    addLine(1, 1, 2, a);
    addLine(2, 2, 3, b);

    for (int i = 1; i <= n; i++) {
        node[i].dist = (1 << 31) - 1;
        node[i].heapLink = i;
        h[i] = i;
    }
    node[s].dist = 0;
    up(s);

    //print();
    for (int i = n; i >= 1; i--) {
        int now = h[1];
        swap(1, i);
        down(1, i - 1);     
        if (node[now].dist == ((1 << 31) - 1)) {
            break;
        }
        update(now);
        //print();
    }

    write(node[3].dist);

    return 0;
}