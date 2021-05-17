// leet421
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use core::num;
use std::collections::*;
use std::cmp::{max, min};

impl Solution {
    pub fn find_maximum_xor(A: Vec<i32>) -> i32 {
        
        let mut ans = 0;

        for i in (0..=30).rev() {
            ans <<= 1;
            let curXor = ans | 1;
            let mut S = HashSet::new();
            for &x in A.iter() {
                if S.contains(&(curXor ^ (x >> i))) { ans = curXor; break; }
                S.insert(x >> i);
            }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_maximum_xor(vec![3,10,5,25,2,8]));
}
