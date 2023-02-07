/*
在树 图中的bfs dfs常用模板
*/

int dfs(int u){
    st[u] = true; // st[u] 表示点u已经被遍历过

    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]) dfs(j);
    }

}

int bfs() {
    int queue[];
    int front = 0, back = -1;   //多利用数组来模拟队列 这样会快很多
    while (front <= back) {
        int f = queue[front++];     //返回队头而且出队
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (check()) {
                queue[++ back] = j;
            }
        }
    }
}