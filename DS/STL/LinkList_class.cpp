#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct ListNode {
    int val = INF + 1;
    ListNode *next = nullptr;
    ListNode() {}
    ListNode(int x) {
        val = x;
    }
    ListNode(ListNode *head) {
        next = head;
    }
};

class List {
public:
    ListNode *head;
    List() {
        head = new ListNode();
    }
    void add(int x) {
        ListNode *tmp = new ListNode(x);
        tmp->next = head->next;
        head->next = tmp;
    }
    void addTail(int x) {
        ListNode *tmp = new ListNode();
        tmp->next = head;
        tmp = tmp->next;
        while(tmp->next) {
            tmp = tmp->next;
        }
        ListNode *v = new ListNode(x);
        tmp->next = v;
    }
    int addMid(int k, int x) {
        if(k <= 0) return 1;
        int len = 0;
        ListNode *tmp = new ListNode(head);
        for(tmp; tmp->next; tmp = tmp->next) len++;
        if(k > len) return 1;
        tmp = new ListNode();
        tmp = head;
        for(int i = 1; i < k && tmp->next; i ++) {
            tmp =  tmp->next;
        }
        ListNode *v = new ListNode(x);
        v->next = tmp->next;
        tmp->next = v;
        return 0;
    }
    int del(int k) {
        if(k <= 0) return 1;
        int len = 0;
        ListNode *tmp = new ListNode(head);
        tmp = tmp->next;
        for (int i = 1; tmp->next; tmp = tmp->next, i ++) {
            if (i == k) {
                tmp->next = tmp->next->next;
                return 0;
            }
        }
        return 1;
    }
    int find(int k) {
        if(k <= 0) return INF;
        int len = 0;
        for(ListNode *tmp = head; tmp->next; tmp = tmp->next) len++;
        if(k > len) return INF; 
        ListNode *tmp = new ListNode();
        tmp->next = head;
        for(int i = 0; i < k; i ++) {
            tmp = tmp->next;
        }
        return tmp->next->val;
    }
    void display() {
        ListNode *tmp = head;
        while(tmp->next) {
            cout << tmp->next->val << ' ';
            tmp = tmp->next;
        }
        cout << endl;
    }

};

int main() {
    List list = List();
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        list.addTail(x);
    }
    list.display();
    for(int i = 0; i < 2; i ++) {
        int k, x;
        cin >> k >> x;
        if(list.addMid(k, x)) puts("error");
        else {
            list.display();
        }
    }
    for(int i = 0; i < 2; i ++) {
        int k;
        cin >> k;
        if(list.del(k)) puts("error");
        else list.display();
    }
    for(int i = 0; i < 2; i ++) {
        int k;
        cin >> k;
        int f = list.find(k);
        if(f == INF) puts("error");
        else cout << f << endl;
    }
    return 0;
}