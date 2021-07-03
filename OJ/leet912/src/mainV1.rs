// leet912
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
    pub fn sort_array(mut A: Vec<i32>) -> Vec<i32> {
        A.sort_unstable();
        A
    }
}

fn main() {
    println!("ans = {:?}", Solution::sort_array(vec![5,1,1,2,0,0]));
}
