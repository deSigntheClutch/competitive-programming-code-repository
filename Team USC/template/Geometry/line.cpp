struct Line {
    int a, b, c;
    Line(int x1, int y1, int x2, int y2) {
        a = y1 - y2, b = -(x1 - x2), c = -a * x1 - b * y1;
        int tmp = gcd(abs(c), gcd(abs(a), abs(b)));
        a /= tmp, b /= tmp, c /= tmp;
        if (a < 0 || (a == 0 && b < 0)) a *= -1, b *= -1, c *= -1;
    }
    bool operator < (struct Line l) const {
        return make_tuple(a, b, c) < make_tuple(l.a, l.b, l.c);
    }
};
