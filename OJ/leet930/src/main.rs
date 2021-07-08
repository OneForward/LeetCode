// leet930
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize, vec};
use std::cmp::{max, min};

impl Solution {
    pub fn num_subarrays_with_sum(A: Vec<i32>, goal: i32) -> i32 {
        let mut ans = 0;
        let mut sum = 0;
        let mut f = vec![0; A.len() + 1]; f[0] = 1;
        if goal == 0 { ans -= A.len() as i32;  }

        for (i, &x) in A.iter().enumerate() {
            sum += x;  f[sum as usize] += 1;
            if sum >= goal { ans += f[(sum - goal) as usize]; }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_subarrays_with_sum( vec![1,0,1,0,1],  2));
    println!("ans = {:?}", Solution::num_subarrays_with_sum( vec![0,0,0,0,0],  0));
}
