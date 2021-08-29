// leet158
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
    pub fn sum_odd_length_subarrays(A: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = A.len();
        for (i, &x) in A.iter().enumerate() {
            let (lft, rht) = (i, n - 1 - i);
            let (lftOdd, rhtOdd) = ((lft + 1) / 2, (rht + 1) / 2);
            let (lftEven, rhtEven) = (lft / 2 + 1, rht / 2 + 1);
            ans += (lftOdd * rhtOdd + lftEven * rhtEven) as i32 * x;
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::sum_odd_length_subarrays(vec![1,4,2,5,3]));
    println!("ans = {:?}", Solution::sum_odd_length_subarrays(vec![1,2]));
    println!("ans = {:?}", Solution::sum_odd_length_subarrays(vec![10,11,12]));
}
