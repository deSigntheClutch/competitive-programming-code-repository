use std::cmp::max;
use std::collections::BTreeMap;
use proconio::input;

fn main() {
    input! {
        n:usize,
        k:usize,
        a:[usize;n],
    }

    let mut cnt: BTreeMap<usize, usize> = BTreeMap::new();
    let mut max_people = 0;
    a.iter().for_each(|&i| {
        *cnt.entry(i).or_insert(0) += 1;
        max_people = max(max_people, *cnt.entry(i).or_insert(0));
    });

    println!("{}", (1..=k).map(|x| if 1 + *cnt.get(&x).unwrap_or(&0)>= max_people {1} else {0}).sum::<usize>());
}