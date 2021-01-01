#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

struct Node {
    int key;
    int val;
    int sum;
    int height;
    Node *l, *r;
};

int total = 0;
Node t[N];

Node *create(int key) {
    Node *ret = &t[total++];
    ret->key = key;
    ret->sum = 1;
    ret->val = 1;
    return ret;
}

int height(Node *x) {
    return x ? x->height : -1;
}

int sum(Node *x) {
    return x ? x->sum : 0;
}

void fix(Node *x) {
    x->height = 1 + max(height(x->l), height(x->r));
    x->sum = x->val + sum(x->l) + sum(x->r);
}

Node *rotL(Node *x) {
    Node *y = x->r;
    x->r = y->l;
    y->l = x;
    fix(x), fix(y);
    return y;
}

Node *rotR(Node *x) {
    Node *y = x->l;
    x->l = y->r;
    y->r = x;
    fix(x), fix(y);
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
        fix(x);
        if (height(x->l) - height(x->r) >= 2) {
            if (height(x->l->l) - height(x->l->r) == 1) {
                x = rotR(x);
            } else {
                x->l = rotL(x->l);
                x = rotR(x);
            }
        }
        return x;
    } else {
        x->r = insert(x->r, key);
        fix(x);
        if (height(x->r) - height(x->l) >= 2) {
            if (height(x->r->r) - height(x->r->l) == 1) {
                x = rotL(x);
            } else {
                x->r = rotR(x->r);
                x = rotL(x);
            }
        }
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
    return 0;
}
