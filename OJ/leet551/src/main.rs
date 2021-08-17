// leet551
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
    pub fn check_record(s: String) -> bool {
        let mut ok = true;
        let (mut A, mut L) = (0, 0);
        for ch in s.bytes() {
            if ch == 'A' as u8 { A += 1; }
            if ch == 'L' as u8 { L += 1; }
            else { L = 0; }
            if A >= 2 || L >= 3 { ok = false; break; }
        }
        ok
    }
}

fn main() {
    println!("ans = {:?}", Solution::check_record("PPALLP".to_string()));
    println!("ans = {:?}", Solution::check_record("PPALLL".to_string()));
}
