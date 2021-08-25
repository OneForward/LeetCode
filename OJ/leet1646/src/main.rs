// leet1646
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
    pub fn get_maximum_generated(n: i32) -> i32 {
        if n == 0 { 0 }
        else {
            let n = n as usize;
        let mut A = vec![0; n+1];
        A[1] = 1;
        for i in 1..=n {
            if i % 2 == 0 { A[i] = A[i / 2]; }
            else { let k = i / 2; A[i] = A[k] + A[k + 1]; }
        }
        A.into_iter().max().unwrap()
        }
    }
}

fn main() {
    println!("ans = {:?}", Solution::get_maximum_generated(0));
    println!("ans = {:?}", Solution::get_maximum_generated(1));
}
