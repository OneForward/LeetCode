// leet474
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    pub fn find_max_form(strs: Vec<String>, M: i32, N: i32) -> i32 {
        let (M, N) = (M as usize, N as usize);
        let mut f = vec![[0; 101]; 101];
        for s in strs {
            let mut C = [0usize; 2];
            for ch in s.into_bytes() {
                C[ ch as usize - '0' as usize ] += 1;
            }
            let (C0, C1) = (C[0], C[1]);
            for m in (0..=M).rev() {
                for n in (0..=N).rev() {
                    if m >= C0 && n >= C1 && f[m][n] < f[m-C0][n-C1] + 1 {
                        f[m][n] = f[m-C0][n-C1] + 1;
                    }
                }
            }
        }
        f[M][N]
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_max_form(vec_string!["10", "0001", "111001", "1", "0"], 5, 3));
    println!("ans = {:?}", Solution::find_max_form(vec_string!["10", "0", "1"], 1, 1));
}
