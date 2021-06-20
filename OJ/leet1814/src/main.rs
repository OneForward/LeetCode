// leet1814
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
    pub fn count_nice_pairs(A: Vec<i32>) -> i32 {
        let MOD = 1_000_000_007;
        let mut M = HashMap::new();
        let rev = |mut x: i32| {  
            let mut y = 0;
            while x > 0 {
                y = y * 10 + x % 10; x /= 10;
            }
            y
        };
        for x in A {
            let entry = M.entry(x - rev(x)).or_insert(0);
            *entry += 1;
        }

        let mut ans = 0i64;
        for &cnt in M.values() {
            ans += cnt * (cnt - 1) / 2 % MOD;
            ans %= MOD;
        }
        ans as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::count_nice_pairs(vec![42,11,1,97]));
    println!("ans = {:?}", Solution::count_nice_pairs(vec![13,10,35,24,76]));
}
