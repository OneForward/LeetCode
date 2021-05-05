// leet740
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
    pub fn delete_and_earn(A: Vec<i32>) -> i32 {
        let mut C = BTreeMap::new();
        for x in A.iter() {
            let cnt = C.entry(x).or_insert(0);
            *cnt += 1;
        }
        let (mut gi2, mut gi1, mut gi, mut prev) = (0, 0, 0, 0);
        for (&x, cnt) in C.into_iter() {
            let mut fi = cnt * x;
            if x - prev == 1 { fi += gi2; }
            else { fi += gi1; }
            gi = max(fi, gi1);
            gi2 = gi1; gi1 = gi; prev = x;
        }
        gi
    }
}

fn main() {
    println!("ans = {:?}", Solution::delete_and_earn(vec![1,1,1,2,4,5,5,5,6]));
    println!("ans = {:?}", Solution::delete_and_earn(vec![3,4,2]));
    println!("ans = {:?}", Solution::delete_and_earn(vec![2, 2, 3, 3, 3, 4]));
}
