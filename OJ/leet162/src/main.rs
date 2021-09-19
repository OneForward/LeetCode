// leet162
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
    pub fn find_peak_element(A: Vec<i32>) -> i32 {
        let (mut lft, mut rht) = (0, A.len()-1);
        while lft < rht {
            let mid = (lft + rht) / 2;
            if A[mid] > A[mid + 1] { rht = mid; }
            else { lft = mid + 1; }
        }
        lft as i32
    }
}
fn main() {
    println!("ans = {:?}", Solution::find_peak_element(vec! [1,2,3,1]));
    println!("ans = {:?}", Solution::find_peak_element(vec! [1,2,1,3,5,6,4]));
}
