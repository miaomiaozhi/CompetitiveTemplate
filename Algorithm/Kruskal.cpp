/*
克鲁斯卡尔 最小生成树算法
常数很小 
O(mlogm) m为边数
流程：
    1、将所有边按照权重从小到大排序 时间复杂度瓶颈
    2、遍历所有边 利用并查集在O(1)时间判断a b是否联通 不连通那就加权 加边
*/

const int N = 100010, M = 2e5 + 10;
struct Edge {   //因为不关心边的顺序 所以也用结构体数组来存储边
    int a, b, w;
    bool operator< (const Edge &E) const {  //重载操作符
        return w < E.w;
    }
}edge[M];

int n, m;
int p[M];   //并查集的parent数组

int find (int a) {  //并查集find    
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}

 sort (edge, edge + m);  //最核心的思想就是从小到大来加边
    
    int res = 0, cnt = 0;   //cnt 代表最小生成树的边数  res 代表最小生成树的权值
    for (int i = 0; i < m; i ++) {
        auto e = edge[i];
        int a = e.a, b = e.b, w = e.w;
        if (find(a) != find(b)) {   //假如a b不在一个连通块当中那就将a b加进来
            res += w;       //加权
            p[find(b)] = find(a);   //将b加到a 的连通块中
            
            cnt++;  //边数+1
        }
    }
    if (cnt < n - 1) puts("impossible");    //假如边数少于n - 1那就一定有离散的点 所以不存在最小生成树
    else cout << res;