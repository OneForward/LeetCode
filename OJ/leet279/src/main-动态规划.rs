// leet279
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
    pub fn num_squares(n: i32) -> i32 {
        let n = n as usize;
        let mut S = vec![0; 100];
        let mut f = vec![i32::MAX; 10000];
        for x in 1..=100 {
            S[x - 1] = x * x;
        }

        f[0] = 0;
        for y in 1..=n {
            for &x2 in S.iter() {
                if x2 > y { break; }
                f[y] = min(f[y], f[y-x2] + 1);
            }
        }
        f[n]
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_squares(12));
    println!("ans = {:?}", Solution::num_squares(13));
}
