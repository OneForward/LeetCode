// leet274
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
    pub fn h_index(mut citations: Vec<i32>) -> i32 {
        let mut h = 0;
        citations.sort_unstable();
        for (i, &x) in citations.iter().rev().enumerate() {
            let i = i as i32;
            if x >= i + 1 { h = i + 1; }
        }
        h 
    }
}

fn main() {
    println!("ans = {:?}", Solution::h_index(vec![3,0,6,1,5]));
}
