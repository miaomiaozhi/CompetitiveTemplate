#include <bits/stdc++.h>
using namespace std;

class SeqList {
    private:
        int *list;
        int max_size = 10000;
        int size;
    public:
         SeqList() {
            list = new int(max_size);
         }
         SeqList(int new_size) {
            max_size = new_size;
            list = new int(max_size);
         }
         ~SeqList() {
            delete []list;
         }
         int getSize() {
            return size;
         }
         int getElem(int i) {   //第i个位置的元素
            return list[i - 1];
         }
         void insert(int k, int x) {    //在第k个位置后面插入一个元素x
            int now = list[k];
            for (int i = size; i >= k; i --) {
                list[i] = list[i - 1];
            }
            list[k - 1] = x;
            size++;
         }
         int deleteElem(int k) {
            if (size == 0 || k > size || k < 1) return -1;
            int ret = list[k - 1];
            for (int i = k - 1; i < size; i ++) {
                list[i] = list[i + 1];
            }
            --size;
            return ret;
         }
        void display() {
            for (int i = 0; i < size; i ++) cout << list[i] << ' ';
        }
};

int main () {
    SeqList list;
    for (int i = 0; i < 10; i ++) list.insert(i + 1, i);
    list.display();
    list.deleteElem(1);
    list.display();
    return 0;
}