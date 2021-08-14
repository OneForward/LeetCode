// leet1137
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, vec};
use std::cmp::{max, min};

impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let n = n as usize;
        let mut f = vec![0; 38];
        f[1] = 1; f[2] = 1;
        for i in 3..=n {
            f[i] = f[i-1] + f[i-2] + f[i-3];
        }
        f[n]
    }
}

fn main() {
    println!("ans = {:?}", Solution::tribonacci(0));
    println!("ans = {:?}", Solution::tribonacci(4));
    println!("ans = {:?}", Solution::tribonacci(25));
}
