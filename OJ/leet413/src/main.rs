// leet413
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
    pub fn number_of_arithmetic_slices(A: Vec<i32>) -> i32 {
        
        let (mut prev, mut cnt) = (999999, 0);
        let mut ans = 0;
        for i in 1..A.len() {
            if A[i] - A[i-1] == prev {
                cnt += 1;
            }
            else {
                ans += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
            prev = A[i] - A[i-1];
        }
        ans += cnt * (cnt - 1) / 2;
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::number_of_arithmetic_slices(vec![1,2,3,4]));
    println!("ans = {:?}", Solution::number_of_arithmetic_slices(vec![1,]));
}
