// lcci10.11
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
    pub fn wiggle_sort(A: &mut Vec<i32>) {
        A.sort();
        let N = A.len();
        let B = A.clone();
        let mut i = 0;
        for j in (N/2..N).rev() {
            A[i] = B[j]; i += 2;
        }
        i = 1;
        for j in 0..N/2 {
            A[i] = B[j]; i += 2;
        }
    }
}

fn main() {
    println!("ans = {:?}", Solution::wiggle_sort(&mut vec![3,5,2,1,6,4]));
}
