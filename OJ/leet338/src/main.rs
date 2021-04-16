// leet338
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::{collections::HashMap, usize};

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn count_bits(num: i32) -> Vec<i32> {
        let mut v = vec![0; (num+1) as usize];
        for i in 1..num+1 {
            v[i as usize] = v[(i-(i&-i)) as usize] + 1;
        }
        v
    }
}
fn main() {
    println!("ans = {:?}", Solution::count_bits(100));
}
