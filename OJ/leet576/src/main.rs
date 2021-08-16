// leet576
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::collections::*;
use std::cmp::{max, min};

impl Solution {
    pub fn find_paths(m: i32, n: i32, max_move: i32, start_row: i32, start_column: i32) -> i32 {
        let MOD = 1e9 as i64 + 7;
        let (m, n) = (m as usize, n as usize);
        let (start_row, start_column) = (start_row as usize, start_column as usize);
        let mut f = vec![vec![0i64; n+2]; m+2];
        for i in 0..m+2 { f[i][0] = 1; f[i][n+1] = 1 };
        for i in 0..n+2 { f[0][i] = 1; f[m+1][i] = 1 };
        for _ in 0..max_move {
            let g = f.clone();
            for r in 1..m+1 {
                for c in 1..n+1 {
                    f[r][c] = (g[r-1][c] + g[r+1][c] + g[r][c-1] + g[r][c+1]) % MOD;
                }
            }
        }
        f[start_row+1][start_column+1] as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_paths(2, 2, 2, 0, 0));
    println!("ans = {:?}", Solution::find_paths(1,3,3, 0,1));
}
