// leet1894
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
    pub fn chalk_replacer(chalk: Vec<i32>,  k: i32) -> i32 {
        let total: i64 = chalk.iter().map(|&x| x as i64).sum();
        let mut k = k as i64;
        k %= total;
        let mut ans = 0;
        for (i, x) in chalk.into_iter().enumerate() {
            k -= x as i64;
            if k < 0 { ans = i; break; }
        }
        ans as i32 
    }
}

fn main() {
    println!("ans = {:?}", Solution::chalk_replacer(vec![5,1,5],   22));
    println!("ans = {:?}", Solution::chalk_replacer(vec![3,4,1,2], 25));
}
