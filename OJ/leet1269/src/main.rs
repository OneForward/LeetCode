// leet1269
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
    pub fn num_ways(T: i32, N: i32) -> i32 {
        let mut f = vec![[0; 505]; 505];
        f[0][1] = 1;
        let (T, N) = (T as usize, N as usize);
        let N = min(T / 2 + 1, N);
        let MOD = 1e9 as usize + 7;
        for t in 0..T {
            for i in 1..=N {
                f[t+1][i] = (f[t][i] + f[t][i-1] + f[t][i+1]) % MOD;
            }
        }
        f[T][1] as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_ways(3, 2));
    println!("ans = {:?}", Solution::num_ways(4, 2));
    println!("ans = {:?}", Solution::num_ways(2, 4));
}
