// leet1590
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
    pub fn min_subarray(A: Vec<i32>, p: i32) -> i32 {
        let delta = p - A.iter().fold(0, |a, b| (a + b) % p);
        if delta == p { 0 }
        else {
            let mut ans = A.len();
            let mut sum = 0;
            let mut H: HashMap<i32, usize> = HashMap::new();
            H.insert(0, 0);
            for (i, &x) in A.iter().enumerate() {
                sum = (sum + x) % p;
                let prev = ( sum + delta ) % p;
                if let Some(j) = H.get(&prev) {
                    ans = min(ans, i - j + 1);
                }
                H.insert(sum, i + 1);
            }
            if ans == A.len() { -1 }
            else { ans as i32 }
        }
    }
}

fn main() {
    println!("ans = {:?}", Solution::min_subarray(vec![3,1,4,2], 6));
    println!("ans = {:?}", Solution::min_subarray(vec![6,3,5,2], 9));
    println!("ans = {:?}", Solution::min_subarray(vec![1,2,3], 3));
    println!("ans = {:?}", Solution::min_subarray(vec![1,2,3], 7));
    println!("ans = {:?}", Solution::min_subarray(vec![1000000000,1000000000,1000000000], 3));
}
