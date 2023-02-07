//  归并排序


#include <iostream>

using namespace std;

const int N = 1e5 + 10 ;                   // 在vscode上面不能开太大的数组 不然会运行不了
int q[N];

int n;

void merge_sort(int q [] , int l ,int r)
{
    int tmp[N];
    int i = l ;
    int mid = (l + r) / 2; 
    int j = mid + 1;
    
    if (l >= r) return;
    
    merge_sort(q , l , mid) , merge_sort(q, mid + 1 , r);
    int k = 0; 
    
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) 
            tmp [k ++] = q[i ++];
        else 
            tmp[k ++] = q[j ++];
        
    }
    
    while (i <= mid ) tmp [k ++] = q[i ++];
    
    while (j <= r ) tmp [k ++] = q[j ++]; 
    
    for (int i = l , j = 0 ; i <= r ; i++ , j ++)
    q[i] = tmp[j];
}

int main()
{
    scanf("%d" , &n);
    
    for (int i = 0 ; i < n ; i ++) scanf("%d" , &q[i]);
         //注意有的时候会报错 “段错误” 主要原因可能是没有选取到 要读入数据的地址 就是说没有加 &
    
    merge_sort(q , 0 ,n - 1);
    
    for (int i = 0 ; i < n ; i ++) printf("%d " , q[i]);
    
}