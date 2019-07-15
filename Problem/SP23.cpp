#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        double a,b,c,l,m,n;
        cin >> l >> n >> a >> m >> b >> c;
        printf("%.4lf\n",sqrt((4 * a * a * b * b * c * c - a * a * (b * b + c * c - m * m) * (b * b + c * c - m * m) - b * b * (c * c + a * a - n * n) * (c * c + a * a - n * n) - c * c * (a * a + b * b - l * l) * (a * a + b * b - l * l) + (a * a + b * b - l * l) * (b * b + c * c - m * m) * (c * c + a * a - n * n))) / 12);
    }

    return 0;
}