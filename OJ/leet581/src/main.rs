// leet581
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
    pub fn find_unsorted_subarray(A: Vec<i32>) -> i32 {
        let N = A.len();
        let (mut lft, mut rht) = (N, 0);
        let (mut maxVal, mut minVal) = (A[0], A[N-1]);
        for i in 0..N {
            if maxVal > A[i] { rht = i; }
            else { maxVal = A[i]; }
        }
        for i in (0..N).rev() {
            if minVal < A[i] { lft = i; }
            else { minVal = A[i]; }
        }
        max(0 , rht as i32 + 1 - lft as i32) 
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_unsorted_subarray(vec![2,6,4,8,10,9,15]));
    println!("ans = {:?}", Solution::find_unsorted_subarray(vec![1,2,3,4]));
    println!("ans = {:?}", Solution::find_unsorted_subarray(vec![1,]));
}
