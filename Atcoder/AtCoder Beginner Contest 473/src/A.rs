use proconio::input;

fn main() {

    input! {
        n: usize,
        a: [u32; n],
    }

    let mut sum = 0;
    // for i in &a[(n / 2)..] 
    for i in n/2..n {
        sum += a[i as usize];
    }
    // let res = a.iter().skip(n / 2).sum::<usize>();
    println!("{}", sum);
}

// 5
// 1 2 0 12 2