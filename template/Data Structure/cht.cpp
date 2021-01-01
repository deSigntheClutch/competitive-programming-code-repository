struct Line {
      long long a, b;
      long long get(long long x) {
            return a * x + b;
      }
};
 
struct ConvexHull {
    int size;
    vector<Line> hull;

    ConvexHull() { this->clear(); }
    void clear() {
        hull.clear(), size = 0;
    }
    bool is_bad(long long curr, long long prev, long long next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
    }
    void add_line(long long a, long long b) {
        hull.push_back((Line){a, b}), size += 1;
        while (size > 2 && is_bad(size - 2, size - 3, size - 1)) 
            hull[size - 2] = hull[size - 1], size--, hull.pop_back();
    }
    long long query(long long x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
                int m = (l + r) / 2;
                if (hull[m].get(x) <= hull[m + 1].get(x)) l = m;
                else r = m;
        }
        return hull[r].get(x);
    }
};