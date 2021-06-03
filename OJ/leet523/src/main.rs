// leet523
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]
#![allow(unused_assignments)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::collections::*;

impl Solution {
    pub fn check_subarray_sum(A: Vec<i32>, k: i32) -> bool {
        let mut f = HashSet::new(); 
        let N = A.len();
        let (mut f1, mut f2) = (0, 0);
        let mut ans = false;
        for x in A {
            f2 = f1; f1 += x; f1 %= k;
            if f.contains(&f1) { ans = true; break; }
            f.insert(f2);
        }
        ans
    }
}

fn main() {
    println!("ans = {:?}", Solution::check_subarray_sum(vec![23,2,4,6,7], 6));
    println!("ans = {:?}", Solution::check_subarray_sum(vec![23,2,6,4,7], 6));
    println!("ans = {:?}", Solution::check_subarray_sum(vec![0], 1));
    println!("ans = {:?}", Solution::check_subarray_sum(vec![23,6,9], 6));
    println!("ans = {:?}", Solution::check_subarray_sum(vec![1,2,3], 5));
}
