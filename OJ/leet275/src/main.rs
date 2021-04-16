// leet275
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
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let (mut lft, mut rht) = (0, n);
        while lft < rht {
            let mid = (lft + rht) / 2;
            if citations[mid] as usize + mid >= n { rht = mid;}
            else {lft = mid + 1;}
        }
        (n - lft) as i32
    }
}

fn main() {
    println!("ans = {:?}", Solution::h_index(vec![0,1,3,5,6]));
}
