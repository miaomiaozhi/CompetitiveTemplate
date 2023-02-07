// TODO: tarjan 
/*
    dfn 表示第一次遍历到 u 的时间戳
    low 表示从 u 开始走到的最上面的点
    stk 表示栈，用于储存当前的一定 不是当前的强联通分量的最高的点
    st 表示是否在栈中
    now 表示时间戳
    scc_cnt 表示强连通分量的数量
    
    id 表示 u 这个点所在的scc编号
    cnt 表示 u 所在的 scc 中的点的个数
*/
vector <int> dfn(n + 1), low(n + 1), stk(n + 5), st(n + 5);
vector <int> id(n + 5), cnt(n + 5);
int now = 0, scc_cnt = 0, top = 0;

function <void(int)> tarjan = [&](int u) -> void {
    dfn[u] = low[u] = ++now;
    stk[++top] = u, st[u] = 1;
    
    for (int v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (st[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int y = 0;
        scc_cnt++;
        do {
            y = stk[top--];
            st[y] = 0;
            id[y] = scc_cnt;
            cnt[scc_cnt]++;
        } while (y != u);
    }
};

for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
}