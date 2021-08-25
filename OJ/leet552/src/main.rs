// leet552
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
    pub fn check_record(n: i32) -> i32 {
        let n = n as usize;
        let MOD = 1e9 as i64 + 7;
        let mut f = vec![1]; f.reserve(n+1);
        let (mut f0, mut f1, mut f2) = (1, 0, 0);
        for i in 1..=n {
            let (g0, g1, g2) = (f0, f1, f2);
            f2 = g1;
            f1 = g0;
            f0 = (g0 + g1 + g2) % MOD;
            f.push((f0 + f1 + f2) % MOD);
        }
        let mut ans = f[n];
        for m in 0..n {
            ans = (ans + f[m] * f[n-1-m]) % MOD;
        }
        ans as i32 
    }
}

fn main() {
    println!("ans = {:?}", Solution::check_record(1));
    println!("ans = {:?}", Solution::check_record(2));
    println!("ans = {:?}", Solution::check_record(10101));
}
