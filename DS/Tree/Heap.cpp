/*
    heap 堆的作用：

    1.插入一个数                up(val) 或者 down(val)
    2.求集合中的最小值          heap[1] 就是最小值
    3.删除集合中的最小值        heap[1] = heap[size]; down(1);
    4.删除第k个任意值          heap[k] = heap[size]; up(k); down(k);
    5.修改第k个任意值          heap[k] = newValue; down(k); up(k);

    堆是一棵完全二叉树

    以小根堆为例：
    每个节点都小于等于左右儿子
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int heap[N], cnt, a[N];

/*
根本思路就是将每个节点u拿出来
然后比较左右孩子
以小根堆为例：
当左右孩子都 >= u的时候 那此时就以及是一个小根堆了
否则就将左右孩子中比u小的 跟u进行交换 然后递归左右孩子
*/

void up(int u) {    //将堆顶调整成大根堆的方法
    int t = u;
    if (2 * u <= cnt && heap[2 * u] > heap[t]) t = 2 * u;
    if (2 * u + 1 <= cnt && heap[2 * u + 1] > heap[t]) t = 2 * u + 1;
    if (u != t) {
        swap(heap[u], heap[t]);
        up(t);
    }
}

void down(int u) {  //将堆顶调整成小根堆的方法
    int t = u;      
    if (2 * u <= cnt && heap[2 * u] < heap[t]) t = 2 * u;
    if (2 * u + 1 <= cnt && heap[2 * u + 1] < heap[t]) t = 2 * u + 1;
    if (t != u) {
        swap(heap[t], heap[u]);
        down(t);
    }
}

void changeKthValue(int k, int v) {
    heap[k] = v;
    up(k);
    down(k);
}

void deleteKth(int k) {
    heap[k] = heap[cnt--];
    up(k);
    down(k);
}

int main () {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> heap[i];
    cnt = n;
    
    for (int i = n / 2; i; i --) up(i);
    changeKthValue(3, 1);
    deleteKth(2);
    while (cnt) {
        cout << heap[1] << " ";
        heap[1] = heap[cnt --];
        up(1);
    }
    return 0;
}