#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int head , e[N] , ne[N] , idx;
//head代表头节点的地址 e[]代表当前节点的数据 ne[]代表当前节点的下一个节点地址
//idx代表当前的操作位置

void init () {      //初始化
    head = -1;
    idx = 0;
}

void add_head (int x) {      //在头节点添加x数据
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void remove(int k) {       //在第k个节点后面删除一个节点
    ne[k] = ne[ne[k]]; 
}

void add_mid(int k , int x) {       //在第k个节点的后面添加一个新的节点
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main () {
    int n ;
    cin >> n;
    init ();
    
    while (n --) {
        char ch;
        cin >> ch;
        int k , x;
        if (ch == 'H') {    //输入H 后在头节点插入
            cin >> x;
            add_head(x);
        }
        else if (ch == 'I') {       //输入I 后在第k个点后插入
            cin >> k >> x;
            add_mid(k - 1 , x);
        }
        else {              //否则输入D 后再第k个点后删除
            cin >> k;
            if (k == 0) head = ne[head];    //因为当k为零的时候就把头节点删除 这时候就把头节点的指针改到
            else remove(k - 1);             //下一个位置就好了
        }
    }
    for (int i = head ; i != -1 ; i = ne[i]) cout << e[i] << " ";
    
    return 0;
}