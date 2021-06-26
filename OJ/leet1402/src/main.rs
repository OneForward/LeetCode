// leet1402
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
    pub fn max_satisfaction(mut satisfaction: Vec<i32>) -> i32 {
        satisfaction.sort(); 

        let (mut f, mut g) = (0, 0);
        for x in satisfaction.iter().rev() {
            g += x;
            if g < 0 { break; }
            else { f += g; }
        }
        
        f
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_satisfaction(vec![-1,-8,0,5,-9]));
    println!("ans = {:?}", Solution::max_satisfaction(vec![4,3,2]));
    println!("ans = {:?}", Solution::max_satisfaction(vec![-1,-4,-5]));
    println!("ans = {:?}", Solution::max_satisfaction(vec![-2,5,-1,0,3,-3]));
}
