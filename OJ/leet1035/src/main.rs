// leet1035
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
    pub fn max_uncrossed_lines(A: Vec<i32>, B: Vec<i32>) -> i32 {
        let (N, M) = (A.len(), B.len());
        let mut f = vec![vec![0; M+1]; N+1];
        for i in 0..N {
            for j in 0..M {
                if A[i] == B[j] { f[i+1][j+1] = f[i][j] + 1; }
                else { f[i+1][j+1] = max(f[i][j+1], f[i+1][j]); }
            }
        }
        f[N][M]
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_uncrossed_lines(vec![2,5,1,2,5], vec![10,5,2,1,5,2]));
}
