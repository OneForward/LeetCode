// leet1884
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
    pub fn two_egg_drop(n: i32) -> i32 {
        // t (t + 1) >= 2 n
        let (mut lft, mut rht) = (0, n);
        while lft < rht {
            let t = (lft + rht) / 2;
            if t * (t + 1) >= 2 * n { rht = t; }
            else { lft = t + 1; }
        }
        lft
    }
}

fn main() {
    println!("ans = {:?}", Solution::two_egg_drop(1));
    println!("ans = {:?}", Solution::two_egg_drop(2));
    println!("ans = {:?}", Solution::two_egg_drop(11));
    println!("ans = {:?}", Solution::two_egg_drop(100));
}
