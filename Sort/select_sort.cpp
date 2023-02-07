// 选择排序
// O(n^2) 从头开始遍历遇到比初始最小值小的就交换位置
#include <iostream>
using namespace std;
const int N = 1e5+ 5;
int q[N];

void select_sort (int q[] , int n) {
    for (int i = 0 ; i < n;  i ++) {
        int idx = i;
        for (int j = i + 1; j < n ; j ++) {
            if (q[j] < q[idx]) idx = j;
        }
        swap (q[i] , q[idx]);
    }
}

int main () {
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++) cin >> q[i];
    select_sort (q , n);
    for (int i = 0; i < n ; i ++) cout << q[i] << " ";
    return 0;
}