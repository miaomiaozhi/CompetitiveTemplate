// 快速排序

#include <iostream>
using namespace std;
const int N = 1e5 + 10;            // 防止超出边境
int q[N];
void quick_sort (int q[] ,int l ,int r) {       // l 和 r 分别代表左边界跟右边界  
    if (l >= r) return;            // 当l r重叠也就是数组只有一个数字的时候就不需要排序了  对于没有返回值的函数 return就是让他强制结束的意思
    // 递归一定要有出口
    int x = q[(l + r) >> 1];           //  q[( l + r) >> 1] 代表着选取了中间位置的那个数字
    int i = l - 1 ; int j = r + 1;
    
    while (i < j) {
        do i++ ; while (q[i] < x);              // 左右的两个指针不断靠近 左指针遇到比 x 大的停下来
        do j-- ; while (q[j] > x);                      //右指针遇到比 x 小的停下来 最后进行交换位置               
        if (i < j) swap(q[i] , q[j]);
    }
    
    quick_sort (q , l , j);
    quick_sort (q , j + 1 , r);
}
int main (){
    int n;
    scanf("%d" , &n);
    for (int i = 0; i < n ; i++)
        scanf("%d" , &q[i]);
    quick_sort (q , 0 , n - 1);
    for (int i = 0 ; i < n ; i++) printf("%d " , q[i]);
 }
