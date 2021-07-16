// leet1846
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
    pub fn maximum_element_after_decrementing_and_rearranging(mut A: Vec<i32>) -> i32 {
        A.sort_unstable();

        let mut prev = 0;
        for x in A {
            prev = min(prev + 1, x);
        }
        prev
    }   
}

fn main() {
    println!("ans = {:?}", Solution::maximum_element_after_decrementing_and_rearranging(vec![73,98,9]));
    println!("ans = {:?}", Solution::maximum_element_after_decrementing_and_rearranging(vec![2,2,1,2,1]));
    println!("ans = {:?}", Solution::maximum_element_after_decrementing_and_rearranging(vec![100,1,1000]));
    println!("ans = {:?}", Solution::maximum_element_after_decrementing_and_rearranging(vec![1,2,3,4,5]));
}
