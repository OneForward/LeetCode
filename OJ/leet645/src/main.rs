// leet645
#![allow(dead_code)]
#![allow(non_snake_case)]
#![allow(unused_variables)]
// #![allow(unused_mut)]
#![allow(unused_macros)]
#![allow(unused_imports)]

extern crate rustutils;
use rustutils::*;


struct Solution;


use std::{collections::*, usize};
use std::cmp::{max, min};

impl Solution {
    pub fn find_error_nums(A: Vec<i32>) -> Vec<i32> {
        let N = A.len() as i32;
        let mut f = 0;
        for i in 1..=N {
            f ^= i;
        }
        for i in A.iter() {
            f ^= i;
        }
        let f = f & (-f);
        let (mut x, mut y) = (0, 0);
        for i in 1..=N {
            if f & i > 0 {
                x ^= i;
            }
            else {
                y ^= i;
            }
        }
        for i in A.iter() {
            if f & i > 0 {
                x ^= i;
            }
            else {
                y ^= i;
            }
        }
        let mut found = false;
        for i in A {
            if x == i { found = true; break; }
        }
        if found { vec![x, y] }
        else { vec![y, x] }

    }
}

fn main() {
    println!("ans = {:?}", Solution::find_error_nums(vec![1,2,2,4]));
    println!("ans = {:?}", Solution::find_error_nums(vec![1,1]));
}
