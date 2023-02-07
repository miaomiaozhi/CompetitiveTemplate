/*
拓扑排序
只适用于 AOV网 （有向无环图）

算法流程：

用队列来执行 ，初始化讲所有入度为0的顶点入队。

主要由以下两步循环执行，直到不存在入度为 0 的顶点为止

选择一个入度为 0 的顶点，并将它输出；
删除图中从顶点连出的所有边。
循环结束，

若输出的顶点数小于图中的顶点数，则表示该图存在回路，即无法拓扑排序，

否则，输出的就是拓扑序列 （不唯一）
*/

/*
证明：
    我们可以知道在初始情况下入度为0的点一定是拓扑排序的首位；
    那么每次操作我们将每个点的入度减少1 假如出现了入度为0 的点j
    那么这个点j一定是新的拓扑排序的对首 其实是一种数学归纳法的证明
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int h[N], e[M], ne[M], inDu[M], idx;

//inDu存的是每个点a的入度 也就是有多少条边从a进入

int q[N], ff = 0, bb = -1;

int n, m;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

bool topsort() {
    for (int i = 1; i <= n; i ++) if (!inDu[i]) q[++ bb] = i;
    while (ff <= bb) {
        int f = q[ff ++];
        for (int i = h[f]; i != -1; i = ne[i]) {
            int j = e[i];
            if (inDu[j]) {
                inDu[j]--;
                if (!inDu[j]) q[++bb] = j;
            }
        }
    }
    return bb == n - 1;
}