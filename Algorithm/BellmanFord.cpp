/*
bellman ford 算法用于处理单源含负权边的最短路问题
而且适用于存在负权回路
操作流程
    for n 次 迭代 n 次
        备份dist数组
        遍历 m 条边
            a->b , w    代表由a到b权值为w
            dist[b] = min(dist[b], backup[a] + w);
    if dist[n] > INF / 2 : 无法到达
    else 可以到达距离为dist[n]
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 505, M = 1e5 + 5;

struct edge {   //bellman ford算法中只需要遍历所有的边就行 不需要记录具体顺序所以只需要用结构体数组存储即可
    int a, b, w;    //表示A->B的一条边的边权是w
}Edge[M];

int dist[N], backup[N]; //backup数组用于备份上一次迭代结束的dist 防止出现串联操作
int n, m, k;

void bellman_ford() {
    memset (dist, 0x3f, sizeof dist);   //初始化距离
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++) {              //迭代k次
        memcpy (backup, dist, sizeof dist);     //每次迭代首先先备份一次数组 防止重复使用其中的值 导致串联
        for (int j = 0; j < m; j ++) {      //遍历每一条边
            int a = Edge[j].a, b = Edge[j].b, w = Edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);      
                // A->B的边中b的距离最小值是b本身的距离 和 备份数组的A的距离加上权值
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");   //由于存在负权边所以最终到终点的时候可能并不是正无穷
    else printf("%d\n", dist[n]);
}