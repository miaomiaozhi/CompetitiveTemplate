//二分图

二分图又称二部图，是图论中的一种特殊模型，英文名叫 Bipartite graph 。
 二分图的节点由两个集合组成，且两个集合内部没有边。 百度的定义： 设 G = ( V, E) 是一个无向图，
 如果顶点 V 可分割为两个互不相交的子集 ( A, B) ，
 并且图中的每条边 ， ( i ， j) 所关联的两个顶点 i 和 j 分别属于这两个不同的顶点集 ( i ϵ A, j ϵ B) ，
 则称图 G 为一个二分图。

 一个图是二分图的充要条件是 图中没有奇数环。也就是环的点数不是奇数。

const int N = 1e5 + 10, M = N << 1;
int h[N], e[M], ne[M], idx;

int n, m;
int colour[N];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c) {
    colour[u] = c;      //首先将u 染成 c
    for (int i = h[u]; ~i ; i = ne[i]) {
        int j = e[i];
        if (!colour[j]) {   //假如j 没有被染色 并且染色石板那就返回 false
            if (!dfs(j, 3 - c)) return false; 
        }
        else if (colour[j] == c) return false;  //假如被染了色而且颜色等于c那就返回 false
    }
    return true;
}

int main () {
    cin >> n >> m;
    memset (h, -1, sizeof h);
    for (int i = 0; i < m; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (!colour[i]) {
            if (!dfs(i, 1)) {
                flag = 0;
                break;
            }
        }
    }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}