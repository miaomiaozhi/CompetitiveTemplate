#include <iostream>
#include <cstring>
using namespace std;
const int N = 105;
typedef long long  LL;
LL c[N][N];

int main () {
    int n;
    cin >> n;
    memset (c , 0 , sizeof(c));
    for (int i = 1; i <= n; i ++) {
        c[i][1] = 1;
        c[i][i] = 1;
    }
    for (int i = 3; i <= n; i ++) {
        for (int j = 2; j <= n; j ++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}