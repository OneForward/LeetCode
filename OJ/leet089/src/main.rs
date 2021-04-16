// leet089
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

struct Solution;

use std::collections::HashMap;

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        let mut f = vec![0; 1<<n];
        for i in 0..1<<n {
            f[i] = (i ^ (i >> 1)) as i32;
        }
        f
    }
}

fn main() {
    println!("ans = {:?}", Solution::gray_code(2));
}
