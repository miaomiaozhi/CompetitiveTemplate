/*

时间复杂度为O(n^2) 其中n为点的个数

单源正权最短路问题  
一般用来解决稠密图 即点的个数很少，边数很多的图
dist[N]
首先将起点dist[1] 设为零 然后将其余点全部设成正无穷
for i ： 1~n
    用没有确定为最短距离的点开始 
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 505;

int g[N][N];    //对于稠密图 我们需要用到邻接矩阵来存储
int dist[N];    //存储每个点到起点的距离    初始化为正无穷
int st[N];  //找到被搜索过的最小值点
int n, m;  

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);//距离初始化成正无穷
    dist[1] = 0;    //将起点距离设置成0
    for (int i = 0; i < n; i ++) {
        int t = -1;     //t代表点abc 其中含义为当前的没有被使用过的距离起点最近的点
        for (int j = 1; j <= n; j ++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = 1;  //t被使用过
        for (int j = 1; j <= n; j ++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);  //利用t当中间变量更新j到起点距离
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;   //假如距离仍然是正无穷那就不可到达
    return dist[n]; //否则那就是可以到达返回最小距离
}