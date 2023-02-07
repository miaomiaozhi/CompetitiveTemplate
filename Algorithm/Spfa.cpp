/*
spfa 对于没有负权回路但是又负权边的图 单源最短路问题
也可以用于判断是否存在负环 一般是O(m)复杂的 最坏情况下是O(n*m)

Dijkstra算法中的st数组保存的是当前确定了到源点距离最小的点，
且一旦确定了最小那么就 不可逆 了(不可标记为true后改变为false)；
SPFA算法中的st数组仅仅只是表示的当前发生过更新的点，
且spfa中的st数组 可逆 (可以在标记为true之后又标记为false)。
顺带一提的是BFS中的st数组记录的是当前已经被遍历过的点。

ellman_ford算法里最后return-1的判断条件写的是dist[n]>0x3f3f3f3f / 2;
而spfa算法写的是dist[n]==0x3f3f3f3f;其原因在于Bellman_ford算法会遍历所有的边，
因此不管是不是和源点连通的边它都会得到更新；但是SPFA算法不一样，它相当于采用了BFS，
因此遍历到的结点都是与源点连通的，因此如果你要求的n和源点不连通，它不会得到更新，还是保持的0x3f3f3f3f。

 Bellman_ford算法可以存在负权回路，是因为其循环的次数是有限制的因此最终不会发生死循环；但是SPFA算法不可以，
 由于用了队列来存储，只要发生了更新就会不断的入队，因此假如有负权回路请你不要用SPFA否则会死循环。
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, M = 2e5 + 5;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], st[N];
int q[N], front, back;  //队列用于存储被更新的缩小的点 注意要用n * m个空间防止越界 因为是静态数组....
//一定要开 N * M ！！！！
int cnt[M];

int n, m;

void add (int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    front = 0, back = -1;
    q[++back] = 1;
    st[1] = 1;  //st数组代表当前的队列里面是否存在点a
    while (front <= back) {
        int f = q[front++];
        st[f] = 0;
        for (int i = h[f]; i != -1; i = ne[i]) {    //遍历f的所有出边
            int j = e[i];
            if (dist[j] > dist[f] + w[i]) {
                dist[j] = dist[f] + w[i];
                cnt[j] = cnt[f] + 1;    //路径可以用这个来统计
                if (cnt[j] >= n)    //假如路径数量大于等于n那就是经过了n+1个点 那么就一定存在负环
                if (!st[j]) q[++back] = j;
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) cout << "impossible";
    else cout << dist[n];
}