// leet5712
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
    pub fn sum_of_floored_pairs(A: Vec<i32>) -> i32 {
        let MAX = 100005;
        let MOD = 1e9 as u64 + 7;

        let mut f = vec![0;  MAX];
        for &x in A.iter() { f[x as usize ] += 1; }
        for i in 1..MAX { f[i] += f[i-1]; }
        
        let mut ans = 0;
        for x in A {
            let x = x as usize;
            for k in 1..=((MAX - 1) / x) {
                let rht = min((k+1) * x, MAX);
                ans += k as u64 * ( f[rht - 1] - f[k * x - 1]  ) % MOD ;
                ans %= MOD;
            }
        }
        ans as i32
    }
}

fn main() {
    // println!("ans = {:?}", Solution::sum_of_floored_pairs(vec![7,7,7,7,7,7,7]));
    // println!("ans = {:?}", Solution::sum_of_floored_pairs(vec![2,5,9]));
    println!("ans = {:?}", Solution::sum_of_floored_pairs(vec![34912,57940,45747]));
}
