#include<iostream>
#include<algorithm>
using namespace std;

struct Game {
    int time;
    int money;

    bool operator < (const Game& g) const {
        return money > g.money;
    }
};

const int MAXN = 500 + 5;

Game game[MAXN];
bool play[MAXN];
int m, n;

int main() {
    cin >> m >> n;

    for(int i = 0; i < n; i++) {
        cin >> game[i].time;
    }
    for(int i = 0; i < n; i++) {
        cin >> game[i].money;
    }
    sort(game, game + n);

    for(int i = 0; i < n; i++) {
        for(int j = game[i].time; j >= 1; j--) {
            if(!play[j]) {
                play[j] = true;
                game[i].money = 0;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        m -= game[i].money;
    }

    cout << m << endl;

    return 0;
}