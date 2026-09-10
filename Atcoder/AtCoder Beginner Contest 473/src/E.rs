use std::collections::HashSet;
use proconio::input;

fn main() {
    input! {
        n:usize, k:usize,
        mut a:[usize;n], // ? what's the type of a ?
    }

    a.iter_mut().for_each(|v| *v %= k);

    let mut prefix = 0;
    for x in a.iter_mut() {
        prefix = (prefix + *x) % k;
        *x = prefix;
    }

    let mut ans = 0;
    let mut used: HashSet<usize> = HashSet::from([0]);
    used.insert(0);

    for i in 0..n {
        if used.contains(&a[i]) {
            ans += 1;
            //println!("Found {i}");
            used.clear();
        }
        used.insert(a[i]);
    }

    println!("{ans}");
}