#include <bits/stdc++.h>
using namespace std;

unsigned random() {
    static unsigned long long x = time(NULL);
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}

struct Node {
    unsigned pri;
    int key;
    int val;
    int sum;
    Node *l, *r;
};

int total = 0;
Node t[10000001];

Node *create(int key) {
    Node *ret = &t[total++];
    ret->key = key;
    ret->sum = 1;
    ret->val = 1;
    ret->pri = random();
    return ret;
}

int sum(Node *x) {
    return x ? x->sum : 0;
}

void fix(Node *x) {
    x->sum = x->val + sum(x->l) + sum(x->r);
}

Node *rotL(Node *x, Node *y) {
    x->r = y->l;
    y->l = x;
    fix(x);
    return y;
}

Node *rotR(Node *x, Node *y) {
    x->l = y->r;
    y->r = x;
    fix(x);
    return y;
}

Node *insert(Node *x, int key) {
    if (!x) {
        return create(key);
    }
    if (x->key == key) {
        x->val++;
        x->sum++;
        return x;
    }
    if (key < x->key) {
        x->l = insert(x->l, key);
        if (x->l->pri > x->pri) x = rotR(x, x->l);
        fix(x);
        return x;
    } else {
        x->r = insert(x->r, key);
        if (x->r->pri > x->pri) x = rotL(x, x->r);
        fix(x);
        return x;
    }
}

void erase(Node *x, int key) {
    if (key == x->key) {
        x->val--;
        x->sum--;
        return;
    }
    if (key < x->key) {
        erase(x->l, key);
    } else {
        erase(x->r, key);
    }
    fix(x);
}

int countLT(Node *x, int key) {
    if (!x) {
        return 0;
    }
    if (key <= x->key) {
        return countLT(x->l, key);
    } else {
        return sum(x->l) + x->val + countLT(x->r, key);
    }
}

int countGT(Node *x, int key) {
    if (!x) {
        return 0;
    }
    if (key >= x->key) {
        return countGT(x->r, key);
    } else {
        return sum(x->r) + x->val + countGT(x->l, key);
    }
}

int main() {
    srand(time(NULL));
    return 0;
}
