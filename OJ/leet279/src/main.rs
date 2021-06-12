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
    pub fn num_squares(mut n: i32) -> i32 {
        // 四平方和定理
        let issquare = |n: i32| { 
            let x = (n as f32).sqrt() as i32;
            x * x == n
        };

        let istwosum = |n: i32| {
            let mut ok = false;
            for x in 1..n {
                if x * x > n { break; }
                if issquare(n - x * x) { ok = true; break; }
            }
            ok
        };

        while n % 4 == 0 { n /= 4; }

        if n % 8 == 7 { 4 }
        else if issquare(n){ 1 }
        else if istwosum(n) { 2 }
        else { 3 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_squares(12));
    println!("ans = {:?}", Solution::num_squares(13));
}
