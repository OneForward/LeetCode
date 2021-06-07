// leet494
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    pub fn find_target_sum_ways(A: Vec<i32>, target: i32) -> i32 {
        let mut f = vec![0; 4005]; f[2000] = 1;
        let bias: i32 = A.iter().sum();
        let target = (target + bias) as usize;
        for x in A {
            for t in (0..=target).rev() {
                f[t + 2000] += f[t + 2000 - 2 * x  as usize];
            }
        }
        f[target + 2000]
    }
}

fn main() {
    println!("ans = {:?}", Solution::find_target_sum_ways(vec![1,1,1,1,1], 3));
}
