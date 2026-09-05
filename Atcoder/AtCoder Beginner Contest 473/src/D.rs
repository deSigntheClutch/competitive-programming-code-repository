use proconio::input;

fn dfs(sum: usize, arr: &mut Vec<usize>, s: usize, e: usize, k: usize) {
    if s == e - 1 {
        if (k - sum) % e != 0 {
            return;
        } else {
            arr[s] = (k - sum) / e;
            let res = arr.iter().map(|v| v.to_string()).collect::<Vec<String>>().join(" ");
            println!("{}", res);
            return;
        }
    }

    let mut inc: usize = 0;
    loop {
        let tmp = sum + inc * (s + 1);
        if tmp > k {
            break;
        }
        arr[s] = inc;
        dfs(tmp, arr, s + 1, e, k);
        arr[s] = 0;
        inc += 1;
    }
}

fn main() {
    input! {
        n:usize,
        k:usize,
    }

    let mut array: Vec<usize> = vec![0; n];

    dfs(0, &mut array, 0, n, k);
}