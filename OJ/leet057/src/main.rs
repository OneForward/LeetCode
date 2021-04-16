// leet057
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
    pub fn two_sum(A: Vec<i32>, target: i32) -> Vec<i32> {
        let  (mut lft, mut rht ) = (0, A.len()-1);
        while lft < rht {
            if A[lft] + A[rht] == target { break; }
            if A[lft] + A[rht] > target {rht -= 1;}
            else {lft += 1;}
        }
        vec![A[lft], A[rht]]
    }
}

fn main() {
    println!("ans = {:?}", Solution::two_sum(vec![2,7,11,15], 9));
}
