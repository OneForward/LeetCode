// leet1567
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
    pub fn get_max_len(A: Vec<i32>) -> i32 {
        let (mut pos, mut neg, mut ans) = (0, 0, 0);
        for x in A {
            if x == 0 { pos = 0; neg = 0; }
            else if x > 0 { 
                pos += 1; if neg > 0 { neg += 1; }
            }
            else { 
                let oldpos = pos;  
                if neg > 0 { pos = neg + 1; }
                else { pos = 0; }
                neg = oldpos + 1; 
            }
            ans = max(ans, pos);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::get_max_len(vec![1,-2,-3,4]));
    println!("ans = {:?}", Solution::get_max_len(vec![0,1,-2,-3,-4]));
    println!("ans = {:?}", Solution::get_max_len(vec![-1,-2,-3,0,1]));
    println!("ans = {:?}", Solution::get_max_len(vec![-1, 2]));
    println!("ans = {:?}", Solution::get_max_len(vec![1,2,3,5,-6,4,0,10]));
}
