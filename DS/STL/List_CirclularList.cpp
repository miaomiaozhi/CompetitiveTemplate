#include <iostream>
#include <algorithm>
using namespace std;
int val[100005] , nextptr[100005] , list[100005] , cnt;
/*
Input ：
第一行为 ：head datanums k （k为按照k个数进行反转）

剩余行输入格式：  Address Data Next
00100 6 4       //非循环的
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

可以分成循环的输入一次 非循环的也输入一次

00100 6 4       //循环的
00000 4 99999
00100 1 12309
68237 6 00100
33218 3 00000
99999 5 68237
12309 2 33218
*/

/*
val 数组负责存储每个节点的数据
nextptr 数组负责存储每个节点对应的下一个地址
list 数组负责存储有序的每个节点的地址 （有序即为每个相邻的下标的点是链接的）
cnt 负责存储有效节点 （可能出现无效节点：离散的未被利用的点）
*/

void init (int list[] , int nextptr[] , int val[] , int head , int n) {     //初始化
    int tmp;
    for (int i = 0 ; i < n ; i ++) {
        cin >> tmp;         //读入当前节点的地址
        cin >> val[tmp] >> nextptr[tmp];            //读入当前节点的数据以及当前节点的下一个节点
    }
    while (head != -1) {
        if (cnt > n) {      //假如循环的话就不要再继续了。
            cnt = n;
            break;
        }
        list[cnt ++] = head;        //将链表按照顺序存储在list中
        head = nextptr[head];
        
    }
}

int FindMid(int list[] , int cnt) {             //找到中点 默认下取整 偶数返回前一个点
    return cnt % 2 == 0 ? val[list[cnt / 2 - 1]] : val[list[cnt / 2]];
}

void Exchange(int list[] , int cnt) {               //奇偶交换
    for (int i = 0 ; i < cnt - 1; i += 2) {
        swap (list[i] , list[i + 1]);
    }
}

bool IsCircular(int list[] , int cnt) {  
    if (nextptr[list[cnt - 1]] == -1) {         //O(1) 地判断一下是否循环假如最后要给节点的下一个地址指向null
                                                //那么就是非循环链表  反之则为循环链表
        cout << "This is not a Circular linked list" << endl;
        return false;
    } else {
        cout << "This is a Circular linked list" << endl;
        return true;
    }
}

void reverseList (int list[] , int cnt , int k) {       //按每k个一组进行反转 ， 剩余不反转
    k %= cnt;       //先对cnt取余 防止重复操作
    for (int i = 0 ; i < cnt / k * k ; i += k) {        //非递归形式    
        reverse (list + i , list + i + k);          //按照每k个来反转     假如想整个都反转那就把k当作cnt就好了
    }
}

void Output (int list[] , int cnt) {        //按照 “ 当前节点地址  当前节点数据  当前节点的下一个地址 ”的格式输出
    for (int i = 0 ; i < cnt ; i ++) {
        if (i == cnt - 1 && !IsCircular(list , cnt)) {
            printf ("%05d %d %d\n" , list[i] , val[list[i]] , -1);
            break;
        }
        printf ("%05d %d %05d\n" , list[i] , val[list[i]] , list[i + 1]);
    } printf ("\n");
}

int main () {
    int head , tmp , n , k;
    cin >> head >> n >> k;
    init(list , nextptr , val , head , n);      //初始化 也就是读入数据
    // reverseList(list , cnt , k);     //反转操作
    // Exchange(list , cnt);                //交换奇偶项
    // cout << FindMid(list , cnt) << endl;         //找到中间值
    // Output(list , cnt);                      //输出
    // IsCircular(list , cnt);         // 判断是否为循环链表
    return 0;
} 