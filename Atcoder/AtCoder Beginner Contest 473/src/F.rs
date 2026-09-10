use proconio::input;

const INF: i64 = 1 << 60;

struct SegmentTree {
    nodes: Vec<i64>,
    lazy: Vec<i64>,
}

impl SegmentTree {
    // Create a default tree with given n as size.
    pub fn new(n: usize) -> SegmentTree {
        SegmentTree {
            nodes: vec![INF; n * 4],
            lazy: vec![0; n * 4],
        }
    }

    // Write
    pub fn build(&mut self, rt: usize, left: usize, right: usize, x: &[i64]) {
        if left == right {
            self.nodes[rt] = x[left - 1];
            return;
        }

        let mid: usize = (left + right) >> 1;
        self.build(rt << 1, left, mid, x);
        self.build(rt << 1 | 1, mid + 1, right, x);
        self.push_up(rt);
    }

    // Update all items in [l, r]
    pub fn update(&mut self, rt: usize, left: usize, right: usize, l: usize, r: usize, delta: i64) {
        if l <= left && right <= r {
            self.nodes[rt] += delta;
            self.lazy[rt] += delta;
            return;
        }
        self.push_down(rt);
        let mid = (left + right) >> 1;
        if l <= mid {
            self.update(rt << 1, left, mid, l, r, delta);
        }
        if r > mid {
            self.update(rt << 1 | 1, mid + 1, right, l, r, delta);
        }
        self.push_up(rt);
    }

    // Query minimum value in [l, r]
    pub fn rmq(&mut self, rt: usize, left: usize, right: usize, l: usize, r: usize) -> i64 {
        if l <= left && right <= r {
            return self.nodes[rt];
        }

        let mid = (left + right) >> 1;
        self.push_down(rt);

        if mid >= r {
            self.rmq(rt << 1, left, mid, l, r)
        } else if mid < l {
            self.rmq(rt << 1 | 1, mid + 1, right, l, r)
        } else {
            let lans = self.rmq(rt << 1, left, mid, l, mid);
            let rans = self.rmq(rt << 1 | 1, mid + 1, right, mid + 1, r);

            std::cmp::min(lans, rans)
        }
    }

    fn push_up(&mut self, rt: usize) {
        self.nodes[rt] = std::cmp::min(self.nodes[rt<<1], self.nodes[rt << 1 | 1]);
    }

    fn push_down(&mut self, rt: usize) {
        if self.lazy[rt] != 0 {
            let d = self.lazy[rt];
            self.lazy[rt << 1] += d;
            self.nodes[rt << 1] += d;
            self.lazy[rt << 1 | 1] += d;
            self.nodes[rt << 1 | 1] += d;
            self.lazy[rt] = 0;
        }
    }
}

fn main() {
    input ! {
        n: usize,
        s: String,
        q: usize,
    }

    let mut vals: Vec<i64> = s.chars().map(|c| if c == 'A' { 1 } else { -1 }).collect();
    let mut pref = vec![0i64; n];
    let mut acc = 0;
    for i in 0..n { acc += vals[i]; pref[i] = acc; }

    let mut tree = SegmentTree::new(n);
    tree.build(1, 1, n, &pref);

    for _ in 0..q {
        input! { t: u8 }
        if t == 1 {
            input! { i: usize, c: char };
            let nv = if c == 'A' { 1 } else { -1 };
            let delta = nv - vals[i - 1];
            if delta != 0 {
                vals[i - 1] = nv;
                tree.update(1, 1, n, i, n, delta);
            }
        } else {
            input! { l: usize, r: usize };
            let base = if l == 1 { 0 } else { tree.rmq(1, 1, n, l - 1, l - 1) };
            let m = tree.rmq(1, 1, n, l, r);
            println!("{}", if m >= base { "Yes" } else { "No" });
        }
    }
}