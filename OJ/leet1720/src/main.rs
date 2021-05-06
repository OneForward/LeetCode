// leet1720
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
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let N = encoded.len();
        let mut ans = vec![0; N+1];
        ans[0] = first;
        for i in 0..N {
            ans[i+1] = ans[i] ^ encoded[i];
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::decode(vec![1,2,3], 1));
    println!("ans = {:?}", Solution::decode(vec![6,2,7,3], 4));
}
