// leet908
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::collections::HashMap;
use std::cmp::max;
use std::cmp::min;

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn smallest_range_i(A: Vec<i32>, k: i32) -> i32 {
        max(A.iter().max().unwrap() - A.iter().min().unwrap() - 2 * k, 0)
    }
}

fn main() {
    println!("ans = {:?}", Solution::smallest_range_i(vec![1], 0));
    println!("ans = {:?}", Solution::smallest_range_i(vec![0, 10], 2));
    println!("ans = {:?}", Solution::smallest_range_i(vec![1,3,6], 3));
}
