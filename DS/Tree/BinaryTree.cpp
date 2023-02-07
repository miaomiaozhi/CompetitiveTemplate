#include <iostream>
using namespace std;

typedef struct BTnode {
    char data;
    struct BTnode *lchild , *rchild;
} BTnode, *BTree;

void CreatTree(BTree *T) {
    char ch;
    cin >> ch;
    if (ch == '#') *T = nullptr;       //if ch == # 那就是一个空结点
    else {
        *T = (BTree) malloc (sizeof(BTnode));   //不为 # 那就是一个节点 因此要先分配内存
        (*T) -> data = ch;  //然后将节点的数据传入
        CreatTree(&(*T) -> lchild); //递归建立左子树     
        CreatTree(&(*T) -> rchild); //递归建立右子树
    }
}

void PreOrder (BTree T) {       //前序遍历
    if (T == nullptr) return;
    printf ("%c " , T -> data);
    PreOrder(T -> lchild);
    PreOrder(T -> rchild);
}

void InOrder (BTree T) {
    if (T == nullptr) return;
    InOrder (T -> lchild);
    printf ("%c " , T -> data);
    InOrder(T -> rchild);
}

void PostOrder (BTree T) {
    if (T == NULL) return;
    PostOrder(T -> lchild);
    PostOrder(T -> rchild);
    printf ("%c " , T -> data);
}

int main () {
    BTree *Tree;
    CreatTree(Tree);
    PreOrder(*Tree);
}

