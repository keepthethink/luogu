#include<iostream>
#include<queue>
using namespace std;

const int MAXN = 500000 + 5;

int c[MAXN][26], cnt;
int val[MAXN];
int fail[MAXN];


/*insert函数：插入新字符串

在这里我们用一个二维数组c[i][j]来表示节点i的j字符所指向的子节点
*/
void insert(string s) {
    int l = s.size(), now = 0;

    for(int i = 0; i < l; i++) {
        int v = s[i] - 'a';

        if(c[now][v] == 0) {
            c[now][v] = ++cnt; //没有该节点，新建
        }

        now = c[now][v]; //修改当前节点
    }

    val[now]++;
}

/*calcNext函数：计算前缀指针

在这里我们用BFS（广度优先搜索）来求出next前缀指针
*/
void calcNext() {
    queue<int> q;

    for(int i = 0; i < 26; i++) {
        if(c[0][i] != 0) {
            fail[c[0][i]] = 0;
            q.push(c[0][i]);
        }
    }

    while(!q.empty()) {
        int now = q.front(); q.pop();

        for(int i = 0; i < 26; i++) {
            if(c[now][i] != 0) {
                fail[c[now][i]] = c[fail[now]][i];
                q.push(c[now][i]);
            } else {
                c[now][i] = c[fail[now]][i];
            }
            /*
            这部分代码理解起来较为困难。

            在伪代码中，应当不断检查当前节点的前缀指针是否拥有i节点，但在这份代码中，可以将其交给第二个判断来完成。
            */
        }
    }
}

int query(string s) {
    int l = s.size(), now = 0, ans = 0;

    for(int i = 0; i < l; i++) {
        int v = s[i] - 'a';

        now = c[now][v];

        for(int t = now; t != 0 && val[t] != -1; t = fail[t]) {
            ans += val[t];
            val[t] = -1;
        }
    }

    return ans;
}

int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;

        cin >> s;

        insert(s);
    }

    calcNext();

    string s;

    cin >> s;

    cout << query(s) << endl;

    return 0;
}