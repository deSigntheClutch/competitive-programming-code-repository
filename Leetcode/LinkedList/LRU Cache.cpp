#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next, *prev;
    Node(int v) {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, int> dict;    
    unordered_map<int, Node*> address;
    
    int cnt, cap;
    Node* head, *tail;
    
    LRUCache(int capacity) {
        cnt = 0;
        dict.clear();
        address.clear();
        cap = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void update(int key) {
        if (head == tail) return;
        Node* cur = address[key];
        if (cur == tail) return;
        cur->next->prev = cur->prev;
        if (cur != head) cur->prev->next = cur->next;
        else head = cur->next;
        cur->prev = tail;
        cur->next = nullptr;
        tail->next = cur;
        tail = cur;
    }
    
    int get(int key) {
        if (dict[key] != 0) update(key);
        return dict[key] - 1;
    }
    
    void put(int key, int value) {
        if (dict[key] != 0) {
            update(key);
            dict[key] = value + 1;
            address[key]->val = key;
            return;
        }
        // frequent list
        if (head == tail && head == nullptr) {
            head = new Node(key);
            tail = head;
            cnt++;
        } else if (cnt < cap) {
            cnt++;
            tail->next = new Node(key);
            if(tail == head) head -> next = tail->next;
            tail->next->prev = tail;
            tail = tail->next;
        } else {
            tail->next = new Node(key);
            tail->next->prev = tail;
            tail = tail->next;
            dict[head->val] = 0;
            address[head->val] = nullptr;
            head = head->next;
            head->prev = nullptr;
        }
        address[key] = tail;
        // update val map
        dict[key] = value + 1;
    }
};
int main() {
    LRUCache test(2);
    test.put(2, 1);
    test.put(2, 2);
    cout << test.get(2) << endl;
    test.put(1, 1);
    test.put(4, 1);
    cout << test.get(2) << endl;
    return 0;
}