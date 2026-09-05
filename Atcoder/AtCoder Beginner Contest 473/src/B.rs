use std::collections::HashMap;
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i64; n],
    }

    let mut used: HashMap<i64, i64> = HashMap::new();
    for &x in &a {
        *used.entry(x).or_insert(0) += 1;
    }

    let mut sum = 0;
    for (&x, &y) in &used {
        sum += if y % 2 == 1 {x} else {0};
    }

    println!("{}", sum);
}