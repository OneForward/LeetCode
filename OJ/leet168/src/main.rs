// leet168
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
    pub fn convert_to_title(mut n: i32) -> String {
        
        let mut s = Vec::new();
        while n > 0 {
            s.push((((n - 1) % 26) as u8 + 'A' as u8) as char); n = (n - 1) / 26;
        }
        s.into_iter().rev().collect()
    }
}

fn main() {

    println!("ans = {:?}", Solution::convert_to_title(701));
    // for x in 1..55 {
    //     println!("{} = {:?}", x,  Solution::convert_to_title(x));
    // }
}
