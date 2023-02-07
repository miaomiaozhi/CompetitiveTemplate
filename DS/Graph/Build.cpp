#include <iostream>
#include <cstring>
using namespace std;

/*
树 图的存储都是这样的 在边权是 1 的情况下
无向图那就将两个方向都加上边
*/

const int N = 1e5 + 5, M = 2e5 + 5;
int head[N];//下标代表点ab这些，存的值是节点指针idx(编号)比如head[a] = 1;val[1] = b;代表a到b有一条边
int val[M];//下标代表idx指针  存的值代表指针对应的点idx = 30; val[30] = b; 代表第三十个节点是b
int ne[M]; //下标代表idx指针  存的值代表下一个节点的指针也就是 (idx')
int w[M];  //假如需要用到权值那就再w数组中记录
int idx; //从0开始 因为是单调递增的 所以每一个节点的编号都不会重复

//加一条从a->b的边
void add(int a, int b) {
    val[idx] = b;       //创建一个新的节点idx 并且记录下节点的value 为 b
    ne[idx] = head[a];  //将当前节点的next指针指向a的头节点
    head[a] = idx++;    //然后将a的头节点指针指向idx 并且idx重新创建
}

//加一条从a->b的带权边 权值为c
void add (int a, int b, int c) {
    val[idx] = b;
    w[idx] = c;     
    ne[idx] = head[a];
    head[a] = idx++;
}

int main() {
    memset (head, -1, sizeof head); //一定要记得要初始化！！！
    return 0;
}


// 对于稠密图 那就需要用到邻接矩阵来存储
int g[N][N];    //下标代表a->b 点 值代表边权

memset(g, 0x3f, sizeof g);  //由于可能存在自环或者重边 所以要这样初始化一下 代表所有边都不能互相到达

for (int i = 0; i < m; i ++) {
    int a, b, w;    //w代表边权
    cin >> a >> b >> w;
    g[a][b] = min(g[a][b], w);      //由于存在自环和重边 所以在记录的时候判断一下就行
}   