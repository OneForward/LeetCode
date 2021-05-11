// leet1734
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
    pub fn decode(encoded: Vec<i32>) -> Vec<i32> {
        let N = encoded.len() + 1;
        let mut ans = Vec::new();
        ans.reserve(N);
        let mut y = 0;
        for i in 1..=N as i32 { y^= i; }
        for i in (1..N).step_by(2) { y ^= encoded[i]; }
        ans.push(y);
        for x in encoded {
            y ^= x;
            ans.push(y);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::decode(vec![3,1]));
    println!("ans = {:?}", Solution::decode(vec![6,5,4,6]));
}
