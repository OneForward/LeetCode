// leet918
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
    pub fn max_subarray_sum_circular(A: Vec<i32>) -> i32 {
        let (mut pos, mut neg, mut allsum, mut ans) = (0, 0, 0, i32::MIN);
        for x in &A {
            if pos <= 0 { pos = *x ;}
            else { pos += x; }
            ans = max(ans, pos); allsum += x;
        }
        for x in &A {
            if neg > 0 { neg = *x ;}
            else { neg += x; }
            if neg != allsum { ans = max(ans, allsum - neg); }
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::max_subarray_sum_circular(vec![0,5,8,-9,9,-7,3,-2]));
}
