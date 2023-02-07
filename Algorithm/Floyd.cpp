/*
O(n^3)
求解多源最短路问题

本质上是基于动态规划
*/

int d[N][N];    //d[a][b] 代表从a到b的最短距离

void floyd() {
    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

/*
因为有松弛操作 且可能存在负权边 所以最后需要判断dist > INF / 2

*/

//为了防止自环出现 可以将i == j的边都设置成0  然后距离初始化为正无穷
for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }