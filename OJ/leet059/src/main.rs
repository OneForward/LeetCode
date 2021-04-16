#![allow(non_snake_case)]

use std::usize;

struct Solution;

impl Solution {
    pub fn generate_matrix(n: i32) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut ans = vec![ vec![0; n]; n ];

        let (mut r, mut c, mut cnt) = (0, 0, 1);
        for x in 0..=(n/2) as usize {
            for c in x..n-x { ans[r][c] = cnt; cnt += 1; } c = n - x - 1;
            for r in x+1..n-x { ans[r][c] = cnt; cnt += 1; } r = n - x - 1;
            for c in (x..n-x-1).rev() { ans[r][c] = cnt; cnt += 1; } c = x;
            for r in (x+1..n-x-1).rev() { ans[r][c] = cnt; cnt += 1; } r = x + 1;
        }
        ans
    }
}

fn main() {
    let n = 3;
    println!("ans = {:?}", Solution::generate_matrix(n));
}
