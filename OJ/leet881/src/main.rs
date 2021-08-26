// leet881
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
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        people.sort_unstable();
        let N = people.len();
        let (mut lft, mut rht) = (0, N-1);
        let mut merged = 0;
        while lft < rht {
            if people[lft] + people[rht] <= limit { 
                merged += 1;
                lft += 1; 
            }
            rht -= 1;
        }
        (N - merged) as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::num_rescue_boats(vec![1,2], 3));
    println!("ans = {:?}", Solution::num_rescue_boats(vec![3,2,2,1], 3));
    println!("ans = {:?}", Solution::num_rescue_boats(vec![3,5,3,4], 5));
}
