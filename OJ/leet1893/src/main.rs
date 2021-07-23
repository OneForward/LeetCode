// leet1893
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
    pub fn is_covered(ranges: Vec<Vec<i32>>, left: i32, right: i32) -> bool {
        let mut ans = true;

        let ok = |x| {
            let mut ok = false;
            for R in ranges.iter() {
                if R[0]  <= x && x <= R[1] { ok = true; break; }
            }
            ok
        };

        for x in left..=right {
            if !ok(x) { ans = false; break; }
        }
        ans 
    }
}

fn main() {
    println!("ans = {:?}", Solution::is_covered(vec2d![[1,2],[3,4],[5,6]], 2, 5));
    println!("ans = {:?}", Solution::is_covered(vec2d![[1,10],[10,20]], 21, 21));
}
