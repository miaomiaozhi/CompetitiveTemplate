/*
prim算法 求最小生成树

S:当前已经在联通块中的所有点的集合

prim 算法中的 dist[]下标代表点a 值存的是a到连通块的最小距离

1. dist[i] = inf        // 
2. for n 次
    t<-S外离S最近的点
    利用t更新S外点到S的距离
    st[t] = true
n次迭代之后所有点都已加入到S中
联系：Dijkstra算法是更新到 起始点 的距离，Prim是更新到 集合S 的距离
*/

int prim() {
    int res = 0;    //最小生成树的边权
    memset (dist, 0x3f, sizeof dist);
    dist[1] = 0;    //初始化所有的点 并且少一点特判 将1号点初始化为0并且加入连通块
    
    for (int i = 0; i < n; i ++) {
        int t = -1;     //t 代表为在连通块中 距离连通块最近的点
        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        if (dist[t] == INF) return INF;     //假如t 距离连通块为INF那就说明无法联通 无法构成最小生成树
        
        res += dist[t];     //加入边权
        st[t] = 1;      //代表t节点已经进入连通块
        
        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], g[t][j]);    //用t更新所有点到联通块的距离
        }
    }
    return res;
}

