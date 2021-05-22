// leet810
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
    pub fn xor_game(A: Vec<i32>) -> bool {
        let mut y = 0;
        for x in A.iter() {
            y ^= x;
        }
        y == 0 || A.len() % 2 == 0
    }
}

fn main() {
    println!("ans = {:?}", Solution::xor_game(vec![1,1,2]));
}
