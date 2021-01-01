#include <bits/stdc++.h>

using namespace std;

struct Node {
	int key;
	int val;
	int sum;
	int height;
	Node *l;
	Node *r;
};

int ptr;
Node pool[10000000];

Node *create(int key) {
	node *ret = &pool[ptr++];
	ret->key = key;
	ret->sum = 1;
	ret->val = 1;
	return ret;
}

int height(node *x) {
	return x ? x->height : -1;
}

int sum(node *x) {
	return x ? x->sum : 0;
}

void fix(node *x) {
	x->height = 1 + max(height(x->l), height(x->r));
	x->sum = x->val + sum(x->l) + sum(x->r);
}

Node *rotL(node *x) {
	Node *y = x->r;
	x->r = y->l;
	y->l = x;
	fix(x);
	fix(y);
	return y;
}

Node *rotR(Node *x) {
	Node *y = x->l;
	x->l = y->r;
	y->r = x;
	fix(x);
	fix(y);
	return y;
}

node *insert(node *x, int key) {
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

void erase(node *x, int key) {
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

int countLT(node *x, int key) {
	if (!x) {
		return 0;
	}
	if (key <= x->key) {
		return countLT(x->l, key);
	} else {
		return sum(x->l) + x->val + countLT(x->r, key);
	}
}

int countGT(node *x, int key) {
	if (!x) {
		return 0;
	}
	if (key >= x->key) {
		return countGT(x->r, key);
	} else {
		return sum(x->r) + x->val + countGT(x->l, key);
	}
}

const int N = 1 << 18;

node *seg[N * 2];

void insertAt(int k, int v) {
	k += N;
	while (k >= 1) {
		seg[k] = insert(seg[k], v);
		k /= 2;
	}
}

void eraseAt(int k, int v) {
	k += N;
	while (k >= 1) {
		erase(seg[k], v);
		k /= 2;
	}
}

int countLT(int l, int r, int key) {
	l += N;
	r += N;
	int ret = 0;
	while (l < r) {
		if (l & 1) {
			ret += countLT(seg[l++], key);
		}
		if (r & 1) {
			ret += countLT(seg[--r], key);
		}
		l /= 2;
		r /= 2;
	}
	return ret;
}

int countGT(int l, int r, int key) {
	l += N;
	r += N;
	int ret = 0;
	while (l < r) {
		if (l & 1) {
			ret += countGT(seg[l++], key);
		}
		if (r & 1) {
			ret += countGT(seg[--r], key);
		}
		l /= 2;
		r /= 2;
	}
	return ret;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = i;
		insertAt(i, a[i]);
	}
	long long inv = 0;
	while (q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		inv -= countGT(0, u, a[u]) + countLT(u, N, a[u]);
		eraseAt(u, a[u]);
		inv -= countGT(0, v, a[v]) + countLT(v, N, a[v]);
		eraseAt(v, a[v]);
		swap(a[u], a[v]);
		insertAt(u, a[u]);
		inv += countGT(0, u, a[u]) + countLT(u, N, a[u]);
		insertAt(v, a[v]);
		inv += countGT(0, v, a[v]) + countLT(v, N, a[v]);
		printf("%lld\n", inv);
	}
}
