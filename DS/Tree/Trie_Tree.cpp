//字典树 又叫trie树

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;

//son数组代表以当前的节点的孩子节点指针p
//cnt 数组代表节点p 所出现的次数
//p代表的意思其实是一个指针 每次我们将从根节点指针开始 一直到字符串最后一个字出现的节点指针

int son[N][30], idx, cnt[N];


// 插入操作 p代表从根节点开始出发
void insert(char *str) {
    int p = 0;
    for (int i = 0; str[i] != '\0'; i ++) {

    //遍历字符串 假如某个节点没有出现的话那就用idx分配一个新的节点
    //利用idx是唯一不重复的 我们可以将将每个节点都独立分开
        int a = str[i] - 'a';
        if (!son[p][a]) son[p][a] = ++idx;
        p = son[p][a];      //假如存在那就去这个节点的子节点
    }
    cnt[p]++;   //最后p节点的出现次数加1
}

int query(char *str) {  //查询操作
    int p = 0;
    for (int i = 0; str[i] != '\0'; i ++) {
        int a = str[i] - 'a';
        if (!son[p][a]) return 0;   //同样的 假如没有出现过那就是0
        p = son[p][a];
    }
    return cnt[p];  //出现过那就返回出现次数
}

void deleteStr(char *str) {     //我们还可以自己写出来删除操作
    int p = 0;
    for (int i = 0; str[i] != '\0'; i ++) {
        int a = str[i] - 'a';
        if (!son[p][a]) return;
        p = son[p][a];
    }
    if (cnt[p]) --cnt[p];   //同样的道理 假如找到那就次数-1即可
}