int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue <PII, vector<PII>, greater<PII>> q;  //用小根堆来优化
    q.push({dist[1], 1});
    
    while (q.size()) {
        auto f = q.top();   q.pop();
        int ver = f.second, distance = f.first;
        if (st[ver]) continue;  //假如已经被选择过当最小点的话那就是冗余点 直接跳过
        st[ver] = true;     //否则就是没有选择过的  判断的位置非常重要
        for (int i = h[ver]; i != -1; i = ne[i]) {  //遍历一遍ver能走到的点 利用这个点来更新距离
            int j = e[i];                   
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                q.push({dist[j], j});   //假如是更新的点那就直接放进去
            }
        }
    }
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
}