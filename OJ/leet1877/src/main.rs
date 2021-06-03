// leet1877
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
    pub fn min_pair_sum(mut A: Vec<i32>) -> i32 {
        A.sort_unstable();
        let N = A.len();
        let mut ans = 0;
        for i in 0..N/2 {
            ans = max(ans, A[i] + A[N-1-i]);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_pair_sum(vec![3,5,2,3]));
    println!("ans = {:?}", Solution::min_pair_sum(vec![3,5,4,2,4,6]));
}
