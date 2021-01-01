double cross(struct Point a, struct Point b) {
    return a.x * b.y - a.y * b.x;
}

void convex_hull() {
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) {
        while (l >= 2 && cross(p[lower_hull[l - 1]] - p[lower_hull[l - 2]], p[i] - p[lower_hull[l - 1]]) <= 0) l--;
        lower_hull[l++] = i;
    }
    for (int i = n; i >= 1; i--) {
        while (r >= 2 && cross(p[upper_hull[r - 1]] - p[upper_hull[r - 2]], p[i] - p[upper_hull[r - 1]]) <= 0) r--;
        upper_hull[r++] = i;
    }
}