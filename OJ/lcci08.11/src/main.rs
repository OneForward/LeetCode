// lcci08.11
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
    pub fn ways_to_change(n: i32) -> i32 {
        let mut f = vec![0; 1000005];
        let g = [1,5,10,25];
        f[0] = 1;
        for &v in g.iter() {
            for x in v..=n as usize {
                f[x] += f[x - v] ; f[x] %= 1_000_000_007;
            }
        }
        f[n as usize]
    }
}

fn main() {
    println!("ans = {:?}", Solution::ways_to_change(10));
    println!("ans = {:?}", Solution::ways_to_change(5));
}
