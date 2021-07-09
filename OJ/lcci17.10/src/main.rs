// lcci17.10
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
    pub fn majority_element(A: Vec<i32>) -> i32 {
        let (mut val, mut cnt) = (A[0], 0);
        for &x in A.iter() {
            if x == val { cnt += 1; }
            else {
                cnt -= 1;
                if cnt == 0 { val = x; cnt = 1; }
            }
        }
        cnt = 0;
        for &x in A.iter() { if x == val { cnt += 1; } }
        if cnt > A.len() / 2 { val }
        else { -1 }
    }
}

fn main() {
    println!("ans = {:?}", Solution::majority_element(vec![1,2,5,9,5,9,5,5,5]));
    println!("ans = {:?}", Solution::majority_element(vec![3,2]));
    println!("ans = {:?}", Solution::majority_element(vec![2,2,1,1,1,2,2]));
}
