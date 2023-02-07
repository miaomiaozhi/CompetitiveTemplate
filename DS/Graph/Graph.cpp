#include <bits/stdc++.h>
using namespace std;

const int N = 1100, M = N << 1;
int e[N], ne[M], w[M], h[M], idx;
int g[N][N];
bool st[N];
int n;
void dfs(int u) {
    if (st[u]) return;
    st[u] = 1;
    cout << u << ' ';
    for (int i = 0; i < n; i ++) {
        if (!g[u][i]) continue;
        dfs(i);
    }
}

void bfs() {
    queue <int> q;
    q.push(0);
    st[0] = 1;
    while (q.size()) {
        int f = q.front();
        q.pop();
        cout << f << ' ';
        for (int i = 0; i < n; i ++) {
            if (g[f][i] && !st[i]) {
                st[i] = 1;
                q.push(i);
            }
        }
    }
    // puts("");
}

void solve() {
    cin >> n;
    memset (g, 0, sizeof g);
    memset (st, false, sizeof st);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }
    // dfs(0);
    bfs();
    cout << endl;
}

int main () {
    int T;
    cin >> T;
    while (T --) {
        solve();
    }
}